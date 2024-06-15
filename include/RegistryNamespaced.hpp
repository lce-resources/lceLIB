#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "lce/processor.hpp"


template<typename T>
class RegistryNamespaced {

    class ResourceLocation {
    public:
        int id;
        std::string identifier;
        const T* object;

        ResourceLocation(int id, std::string identifier, const T* object)
            : id(id), identifier(std::move(identifier)), object(object) {}

        ~ResourceLocation() = default;

        ND std::string toString() const {
            std::string str = "ResourceLocation{" + std::to_string(id) + ", \"" + identifier + "\", ";
            if (object == nullptr) {
                str += "nullptr";
            } else {
                str += "obj";
            }
            str += "}";
            return str;
        }
    };

    std::vector<ResourceLocation*> allValues;

    /// function to get a reference to the static idRegistry map
    static std::unordered_map<int, ResourceLocation*>& getIdRegistry() {
        static std::unordered_map<int, ResourceLocation*> idRegistry;
        return idRegistry;
    }

    /// function to get a reference to the static identifierRegistry map
    static std::unordered_map<std::string, ResourceLocation*>& getIdentifierRegistry() {
        static std::unordered_map<std::string, ResourceLocation*> identifierRegistry;
        return identifierRegistry;
    }

public:
    RegistryNamespaced() = default;
    ~RegistryNamespaced() { clear(); }

    void registerValue(int id, const std::string& identifier, const T* object) {
        if (object == nullptr) {
            throw std::invalid_argument("Object cannot be null.");
        }

        auto* pResourceLocation = new ResourceLocation(id, identifier, object);

        if (id >= allValues.size()) {
            allValues.resize(id + 1, nullptr);
        }

        if (allValues[id] != nullptr) {
            delete allValues[id];
        }

        allValues[id] = pResourceLocation;
        getIdRegistry()[id] = pResourceLocation;
        getIdentifierRegistry()[identifier] = pResourceLocation;
    }

    T const* getObjectById(int id) const {
        auto& idRegistry = getIdRegistry();
        if (idRegistry.count(id) == 0) {
            return nullptr;
        }
        return idRegistry.at(id)->object;
    }

    T const* getObjFromName(const std::string& identifier) const {
        auto& identifierRegistry = getIdentifierRegistry();
        if (identifierRegistry.count(identifier) == 0) {
            return nullptr;
        }
        return identifierRegistry.at(identifier)->object;
    }

    T const* operator[](int index) const {
        if (index < 0 || index >= allValues.size() || allValues[index] == nullptr) {
            throw std::out_of_range("Index out of range or no object at this index.");
        }
        return allValues[index]->object;
    }

    MU const std::vector<ResourceLocation*>& getAllValues() const { return allValues; }

    MU ND int size() const { return allValues.size(); }

    void clear() {
        std::unordered_set<ResourceLocation*> deletedValues;
        for (auto& value : allValues) { delete value; }

        allValues.clear();
        getIdRegistry().clear();
        getIdentifierRegistry().clear();
    }
};
