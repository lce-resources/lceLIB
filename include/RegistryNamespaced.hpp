#pragma once

#include "lce/blocks/block.hpp"
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


/**
 * Functions:
 *   void registerValue(int id, const std::string& name, const T* object)
 *   T* getObjectById(int id) const
 *   T* getObjectByName(const std::string& name) const
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
        std::string name;
        const T* object;

        ResourceLocation(int id, std::string  name, const T* object)
            : id(id), name(std::move(name)), object(object) {}
    };

    std::vector<ResourceLocation*> allValues;
    std::unordered_map<int, ResourceLocation*> idRegistry;
    std::unordered_map<std::string, ResourceLocation*> nameRegistry;

public:
    RegistryNamespaced() = default;
    ~RegistryNamespaced() { clear(); }

    /**
     * .
     * @param id
     * @param name
     * @param object
     */
    void registerValue(int id, const std::string& name, const T* object) {
        if (idRegistry.count(id) > 0 || nameRegistry.count(name) > 0) {
            throw std::invalid_argument("ID or name already exists in the registry.");
        }
        auto* pResourceLocation = new ResourceLocation(id, name, object);
        
        if (id >= allValues.size()) {
            allValues.resize(id + 1, nullptr);
        }
        allValues[id] = pResourceLocation;
        idRegistry[id] = pResourceLocation;
        nameRegistry[name] = pResourceLocation;
    }

    /**
     * .
     * @param id
     * @return
     */
    T* getObjectById(int id) const {
        if (idRegistry.count(id) == 0) {
            return nullptr;
        }
        return &(idRegistry.at(id)->object);
    }

    /**
     * .
     * @param name
     * @return
     */
    T* getObjectByName(const std::string& name) const {
        if (nameRegistry.count(name) == 0) {
            return nullptr;
        }
        return &(nameRegistry.at(name)->object);
    }

    /**
     * .
     * @param index
     * @return
     */
    T* operator[](int index) const {
        if (index < 0 || index >= allValues.size() || allValues[index] == nullptr) {
            throw std::out_of_range("Index out of range or no object at this index.");
        }
        return &(allValues[index]->object);
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
        nameRegistry.clear();
    }
};
