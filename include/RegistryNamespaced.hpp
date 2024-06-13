#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


#include "lce/processor.hpp"


/**
 * Functions:
 *   void registerValue(int id, const std::string& name, const T* object)
 *   T* getObjectById(int id) const
 *   T* getObjectByIdentifier(const std::string& name) const
 *   T* operator[](int index) const
 *   const std::vector<ResourceLocation*>& getAllValues() const
 *   int size() const
 *   void clear()
 *
 * @tparam T
 */
template<typename T>
class RegistryNamespaced {

    /// inner class
    class ResourceLocation {
    public:
        int id;
        std::string identifier;
        const T* object;

        ResourceLocation(int id, std::string identifier, const T* object)
            : id(id), identifier(std::move(identifier)), object(object) {}
    };

    std::vector<ResourceLocation*> allValues;
    std::unordered_map<int, ResourceLocation*> idRegistry;
    std::unordered_map<std::string, ResourceLocation*> identifierRegistry;

public:
    RegistryNamespaced() = default;
    ~RegistryNamespaced() { clear(); }

    /**
     * .
     * @param id
     * @param identifier
     * @param object
     */
    void registerValue(int id, const std::string& identifier, const T* object) {
        if (idRegistry.count(id) > 0 || identifierRegistry.count(identifier) > 0) {
            if (getObjectById(id) != getObjectByIdentifier(identifier)) {
                throw std::invalid_argument(
                        "Separate objects own the id and identifier passed. They must be unique.");
            }

        }
        auto* pResourceLocation = new ResourceLocation(id, identifier, object);
        
        if (id >= allValues.size()) {
            allValues.resize(id + 1, nullptr);
        }
        allValues[id] = pResourceLocation;
        idRegistry[id] = pResourceLocation;
        identifierRegistry[identifier] = pResourceLocation;
    }


    /**
     * This one does not require passing an identifier.
     * If you plan to use this instead, do not use getObjectByIdentifier().
     * @param id
     * @param identifier
     * @param object
     */
    void registerValue(int id, const T* object) {
        if (idRegistry.count(id) > 0) {
            throw std::invalid_argument("ids passed must be unique.");
        }
        auto* pResourceLocation = new ResourceLocation(id, "", object);

        if (id >= allValues.size()) {
            allValues.resize(id + 1, nullptr);
        }
        allValues[id] = pResourceLocation;
        idRegistry[id] = pResourceLocation;
    }

    /**
     * .
     * @param id
     * @return
     */
    T const* getObjectById(int id) const {
        if (idRegistry.count(id) == 0) {
            return nullptr;
        }
        return idRegistry.at(id)->object;
    }

    /**
     * .
     * @param identifier
     * @return
     */
    T const* getObjectByIdentifier(const std::string& identifier) const {
        if (identifierRegistry.count(identifier) == 0) {
            return nullptr;
        }
        return identifierRegistry.at(identifier)->object;
    }

    /**
     * .
     * @param index
     * @return
     */
    T const* operator[](int index) const {
        if (index < 0 || index >= allValues.size() || allValues[index] == nullptr) {
            throw std::out_of_range("Index out of range or no object at this index.");
        }
        return allValues[index]->object;
    }

    /**
     * .
     * @return
     */
    const std::vector<ResourceLocation*>& getAllValues() const { return allValues; }

    /**
     * .
     * @return
     */
    ND int size() const { return allValues.size(); }

    /**
     * .
     */
    void clear() {
        for (const ResourceLocation* value : allValues) { delete value; }
        allValues.clear();
        idRegistry.clear();
        identifierRegistry.clear();
    }
};
