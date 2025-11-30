#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.containers.h>
#include <godmode.foundation/$_dependencies/std.type_traits.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.foundation/types/Json_$.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/DefaultValue.h>

godmode_foundation_types_$
template <
    class IndexType,
    class ValueType,
    class ValueAccessType = typename std::conditional<
        std::is_pointer<ValueType>::value,
        ValueType,
        ValueType*
    >::type
> class Map { $
    using std_map = std::map<IndexType, ValueType>;
    using IndexValuePair = std::pair<const IndexType, ValueType>;
    using InitializerMap = std::initializer_list<IndexValuePair>;
    std_map $map;
    constructor(Map() {})
    constructor(Map(std_map& map) { this->add(map); })
    constructor(Map(InitializerMap map) { this->add(map); })
    constructor(Map(JsonValue& json) { this->add(json); })
    ValueAccessType at(const IndexType& index) {
        auto it = this->findIteration(index);
        if (it != this->$map.end())
            return this->pick(it);
        return nullptr; }
    int length() { return this->$map.size(); }
    bool includes(const ValueType& item) { return this->findValueIteration(item) != this->$map.end(); }
    IndexType* indexOf(const ValueType& item, Function<bool(ValueType, ValueType)> comparator = [](ValueType a, ValueType b) { return a == b; }) {
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); it++)
            if (comparator(item, it->second)) return const_cast<IndexType*>(&it->first);
        return nullptr;
    }
    Map& add(IndexType index, ValueType item, bool preserve = false) {
        if (preserve)
            this->$map.insert(std::pair<IndexType, ValueType>(index, item));
        else
            this->$map[index] = item;
        return *this;
    }
    Map& add(Map& map, bool preserve = false) {
        for (auto it = map.$map.begin(); it != map.$map.end(); ++it) this->add(it->first, it->second, preserve);
        return *this;
    }
    Map& add(InitializerMap map, bool preserve = false) {
        for (auto it = map.begin(); it != map.end(); ++it) this->add(it->first, it->second, preserve);
        return *this;
    }
    Map& add(JsonValue& json, bool preserve = false) {
        for (const auto& key : json.getMemberNames())
            if (json[key].isString())
                this->add(key, json[key].asString());
            else if (json[key].isDouble() || json[key].isInt())
                this->add(key, json[key].asDouble());
        return *this;
    }
    ValueAccessType removeAt(IndexType index, bool _delete = false) {
        ValueAccessType item = this->at(index);
        if (item) {
            this->setBuffer(item);
            this->$map.erase(index);
            this->safeDelete(item, _delete);
            return this->getBuffer();
        }
        return item;
    }
    Map& remove(ValueType item, bool _delete = false) {
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); ++it)
            if (it->second == item) {
                this->removeAt(it->first, _delete);
                break;
            }
        return *this;
    }
    Map& clear(bool _delete = false) {
        while (this->$map.size())
            this->removeAt(this->$map.begin()->first, _delete);
        return *this;
    }
    Map& forEach(Function<void(const ValueType& item, const IndexType& index)> handler) {
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); ++it)
            handler(it->second, it->first);
        return *this;
    }
    Map& forEach(Function<void(const ValueType& item)> handler) {
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); ++it)
            handler(it->second);
        return *this;
    }
    Map filter(Function<bool(const ValueType& item, const IndexType& index)> predicate) {
        Map result;
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); ++it)
            if (predicate(it->second, it->first))
                result.add(it->first, it->second);
        return result;
    }
    Map filter(Function<bool(const ValueType& item)> predicate) {
        Map result;
        for (std_map::iterator it = this->$map.begin(); it != this->$map.end(); ++it)
            if (predicate(it->second))
                result.add(it->first, it->second);
        return result;
    }
    List<ValueType, ValueAccessType> toList() {
        List<ValueType, ValueAccessType> list;
        this->forEach([&](ValueType item) {
            list.add(item); });
        return list;
    }
    Map& operator=(Map& map) { return this->clear().add(map); }
    Map& operator=(InitializerMap map) { return this->clear().add(map); }
    Map& operator=(JsonValue& json) { return this->clear().add(json); }
    bool operator==(Map& map) {
        return this->length() == map.length()
            && this->filter([this, &map](const ValueType& item, const IndexType& index) {
                return this->at(index) && map.at(index) && *this->at(index) == *map.at(index);
            }).length() == this->length(); }
    bool operator!=(Map& map) { return !(*this == map); }
    ValueType& operator[](IndexType index) { return this->$map[index]; }
    Map& operator+=(Map& map) { return this->add(map); }
    Map operator+(Map& map) { return Map().add(*this).add(map); }
protected:
    typename std_map::iterator findIteration(IndexType index) {
        std_map::iterator it = this->$map.end();
        for (std_map::iterator iTer = this->$map.begin(); iTer != this->$map.end(); iTer++)
            if (iTer->first == index) {
                it = iTer;
                break;
            }
        return it;
    }
    typename std_map::iterator findValueIteration(ValueType item) {
        std_map::iterator it = this->$map.end();
        for (std_map::iterator iTer = this->$map.begin(); iTer != this->$map.end(); iTer++)
            if (iTer->second == item) {
                it = iTer;
                break;
            }
        return it;
    }
private:
    ValueType $buffer = DefaultValue<ValueType>::get();
    template <typename T = ValueType>
    typename std::enable_if<std::is_pointer<T>::value, T>::type pick(typename std_map::iterator it) {
        return it->second;
    }
    template <typename T = ValueType>
    typename std::enable_if<!std::is_pointer<T>::value, T*>::type pick(typename std_map::iterator it) {
        return &it->second;
    }
    template <typename T = ValueType, typename std::enable_if<std::is_pointer<T>::value, int>::type = 0>
    void setBuffer(ValueAccessType item) { this->$buffer = item; }
    template <typename T = ValueType, typename std::enable_if<!std::is_pointer<T>::value, int>::type = 0>
    void setBuffer(ValueAccessType item) { this->$buffer = *item; }
    template <typename T = ValueType, typename std::enable_if<std::is_pointer<T>::value, int>::type = 0>
    ValueAccessType getBuffer() { return this->$buffer; }
    template <typename T = ValueType, typename std::enable_if<!std::is_pointer<T>::value, int>::type = 0>
    ValueAccessType getBuffer() { return &this->$buffer; }
    template <typename T = ValueType>
    typename std::enable_if<std::is_pointer<T>::value, void>::type safeDelete(ValueAccessType item, bool _delete) {
        if (_delete)
            delete item;
    }
    template <typename T = ValueType>
    typename std::enable_if<!std::is_pointer<T>::value, void>::type safeDelete(ValueAccessType item, bool _delete) {}
    s11n$defineInline ( ar & this->$map; );
}
godmode_foundation_types_$$