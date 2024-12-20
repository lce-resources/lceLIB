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
        std::string name;
        const T* object;

        ResourceLocation(int id, std::string name, const T* object)
            : id(id), name(std::move(name)), object(object) {}

        ~ResourceLocation() = default;

        MU ND std::string toString() const {
            std::string str = "ResourceLocation{" + std::to_string(id) + ", \"" + name + "\", ";
            if (object == nullptr) {
                str += "nullptr";
            } else {
                str += "obj";
            }
            str += "}";
            return str;
        }
    };

    mutable std::string myName;
    std::vector<ResourceLocation*> allValues;
    std::unordered_map<int, ResourceLocation*> idRegistry;
    std::unordered_map<std::string, ResourceLocation*> nameRegistry;
    /*
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
     */


public:
    RegistryNamespaced() = default;
    explicit RegistryNamespaced(std::string nameIn) : myName(std::move(nameIn)) {}

    ~RegistryNamespaced() {
        clear();
    }

    void setName(std::string nameIn) {
        myName = std::move(nameIn);
    }

    std::string getName() {
        return myName;
    }

    void registerValue(size_t id, const std::string& identifier, const T* object) {
        if (object == nullptr) {
            throw std::invalid_argument("Object cannot be null.");
        }

        auto* pResourceLocation = new ResourceLocation(id, identifier, object);

        allValues.push_back(pResourceLocation);
        idRegistry[id] = pResourceLocation;
        nameRegistry[identifier] = pResourceLocation;
    }

    T const* getObjFromId(int id) const {
        if (idRegistry.count(id) == 0) {
            return nullptr;
        }
        return idRegistry.at(id)->object;
    }

    T const* getObjFromName(const std::string& identifier) const {
        if (nameRegistry.count(identifier) == 0) {
            return nullptr;
        }
        return nameRegistry.at(identifier)->object;
    }

    T const* operator[](int index) const {
        if (index < 0 || index >= allValues.size() || allValues[index] == nullptr) {
            throw std::out_of_range("Index out of range or no object at this index.");
        }
        return allValues[index]->object;
    }

    MU const std::vector<ResourceLocation*>& getAllValues() const { return allValues; }

    MU ND int size() const { return allValues.size(); }

    void clear(bool alsoDeleteObjPtrs = false) {
        myName = "";

        for (size_t i = 0; i < allValues.size(); i++) {
            if (allValues[i] != NULL && allValues[i] != nullptr) {
                if (alsoDeleteObjPtrs) {
                    delete allValues[i]->object;
                }
                allValues[i]->object = nullptr;
                delete allValues[i];
                allValues[i] = nullptr;
            }
        }

        allValues.clear();
        idRegistry.clear();
        nameRegistry.clear();
    }
};
