#pragma once

#include "lce/processor.hpp"


template<typename T>
class RegistryNamespaced {

    class ResourceLocation {
    public:
        int m_id;
        std::string m_identifier;
        std::string m_name;
        const T* m_object;

        ResourceLocation(const int id, std::string identifier, std::string name, const T* object)
            : m_id(id), m_identifier(std::move(identifier)), m_name(std::move(name)), m_object(object) {}

        ~ResourceLocation() = default;

        MU ND std::string toString() const {
            std::string str = "ResourceLocation{" + std::to_string(m_id) + ", \"" + m_name + "\", ";
            if (m_object == nullptr) {
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
    std::unordered_map<std::string, ResourceLocation*> identifierRegistry;
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

    void setName(std::string nameIn) const {
        myName = std::move(nameIn);
    }

    std::string getName() const {
        return myName;
    }

    void registerValue(size_t id, const std::string& identifier, const std::string& name, const T* object) {
        if (object == nullptr) {
            throw std::invalid_argument("Object cannot be null.");
        }

        auto* pResourceLocation = new ResourceLocation(id, identifier, name, object);

        allValues.push_back(pResourceLocation);
        idRegistry[id] = pResourceLocation;
        identifierRegistry[identifier] = pResourceLocation;
        nameRegistry[name] = pResourceLocation;
    }

    T const* getObjFromId(int id) const {
        if (!idRegistry.contains(id)) {
            return nullptr;
        }
        return idRegistry.at(id)->m_object;
    }

    T const* getObjFromIdentifier(const std::string& identifier) const {
        if (!identifierRegistry.contains(identifier)) {
            return nullptr;
        }
        return identifierRegistry.at(identifier)->m_object;
    }

    T const* getObjFromName(const std::string& identifier) const {
        if (!nameRegistry.contains(identifier)) {
            return nullptr;
        }
        return nameRegistry.at(identifier)->m_object;
    }

    T const* operator[](int index) const {
        if (index < 0 || index >= allValues.size() || allValues[index] == nullptr) {
            throw std::out_of_range("Index out of range or no object at this index.");
        }
        return allValues[index]->object;
    }

    MU const std::vector<ResourceLocation*>& getAllValues() const { return allValues; }

    MU ND int size() const { return allValues.size(); }

    void clear(const bool alsoDeleteObjPtrs = false) {
        myName = "";

        for (size_t i = 0; i < allValues.size(); i++) {
            if (allValues[i] != NULL && allValues[i] != nullptr) {
                if (alsoDeleteObjPtrs) {
                    delete allValues[i]->m_object;
                }
                allValues[i]->m_object = nullptr;
                delete allValues[i];
                allValues[i] = nullptr;
            }
        }

        allValues.clear();
        idRegistry.clear();
        nameRegistry.clear();
    }
};
