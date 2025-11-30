#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Json.h>
#include <godmode.foundation/types/List.h>
#include <godmode.foundation/types/Map.h>

godmode_foundation_types_$
template <
    class IndexType,
    class ValueType,
    class ValueAccessType = typename std::conditional<
        std::is_pointer<ValueType>::value,
        ValueType,
        ValueType*
    >::type
> class MappedList { $
    Map<IndexType, ValueType, ValueAccessType> $map;
    List<ValueType, ValueAccessType> $list;
    using IndexValuePair = std::pair<const IndexType, ValueType>;
    using InitializerMap = std::initializer_list<IndexValuePair>;
    using TypedMap = Map<IndexType, ValueType, ValueAccessType>;
    constructor(MappedList() {})
    constructor(MappedList(Map<IndexType, ValueType, ValueAccessType>& map) { this->add(map); })
    constructor(MappedList(InitializerMap map) { this->add(map); })
    constructor(MappedList(JsonValue& json) { this->add(json); })
    int length() { return this->$list.length(); }
    int mapLength() { return this->$map.length(); }
    template <typename I = IndexType, typename L = ValueType, typename std::enable_if<!std::is_same<I, L>::value, int>::type = 0>
    bool includes(const IndexType& index) { return this->$map.at(index) != nullptr; }
    bool includes(const ValueType& item) { return this->$list.includes(item); }
    int indexOf(ValueType item) { return this->$list.indexOf(item); }
    IndexType* mapIndexBy(int index) { return this->$list.at(index) != nullptr ? this->$map.indexOf(this->$list[index]) : nullptr; }
    IndexType* mapIndexOf(ValueType item) { return this->$map.indexOf(item); }
    template <typename T = IndexType, typename std::enable_if<!std::is_arithmetic<T>::value, int>::type = 0>
    ValueAccessType at(const int index) { return this->$list.at(index); }
    ValueAccessType at(const IndexType index) { return this->$map.at(index); }
    ValueAccessType front() { return this->$list.front(); }
    ValueAccessType back() { return this->$list.back(); }
    MappedList& add(IndexType index, ValueType item, bool preserve = false) {
        this->$map.add(index, item, preserve);
        this->$list.add(item);
        return *this;
    }
    MappedList& add(MappedList& mappedList, bool preserve = false) {
        this->$map.add(mappedList.$map, preserve);
        this->$list.add(mappedList.$list);
        return *this;
    }
    MappedList& add(TypedMap& map, bool preserve = false) {
        this->$map.add(map, preserve);
        this->$list.add(map.toList());
        return *this;
    }
    MappedList& add(InitializerMap initializerMap, bool preserve = false) {
        for (auto it = initializerMap.begin(); it != initializerMap.end(); ++it) this->add(it->first, it->second, preserve);
        return *this;
    }
    MappedList& add(JsonValue& json, bool preserve = false) {
        TypedMap map = json;
        this->$map.add(map, preserve);
        this->$list.add(map.toList());
        return *this;
    }
    MappedList& unshift(IndexType index, ValueType item, bool preserve = false) {
        this->$list.unshift(item);
        this->$map.add(index, item, preserve);
        return *this;
    }
    MappedList& modify(const IndexType& index, const ValueType& item) {
        if (this->includes(index)) {
            ValueType element = this->$map[index];
            for (int i = 0; i < this->$list.length(); i++)
                if (this->$list[i] == element) this->$list[i] = item;
            this->$map[index] = item;
        } else
            this->add(index, item);
        return *this;
    }
    MappedList& remove(ValueType item, bool _delete = false) {
        this->$map.remove(item, false);
        this->$list.remove(item, _delete);
        return *this;
    }
    ValueAccessType removeBy(int index, bool _delete = false) {
        ValueAccessType accessTypeItem = nullptr;
        if (index >= 0 && index < this->$list.length()) {
            ValueType item = this->$list[index];
            this->$map.remove(item, false);
            accessTypeItem = this->$list.removeAt(index, _delete);
        }
        return accessTypeItem;
    }
    ValueAccessType removeAt(IndexType index, bool _delete = false) {
        ValueAccessType item = this->$map.at(index);
        this->$list.remove(item, false);
        this->$map.removeAt(index, _delete);
        return item;
    }
    MappedList& clear(bool _delete = false) {
        this->$list.clear(false);
        this->$map.clear(_delete);
        return *this;
    }
    MappedList& forEach(Function<void(const ValueType& item, int index)> handler) { this->$list.forEach(handler); return *this; }
    MappedList& forEach(Function<void(const ValueType& item)> handler) { this->$list.forEach(handler); return *this; }
    MappedList& operator=(MappedList& mappedList) { return this->clear().add(mappedList); }
    MappedList& operator=(InitializerMap map) { return this->clear().add(map); }
    MappedList& operator=(JsonValue& json) { return this->clear().add(json); }
    bool operator==(MappedList& mappedList) {
        return this->length() == mappedList.length()
            && this->$map.filter([this, &mappedList](const ValueType& item, const IndexType& index) {
                return this->at(index) && mappedList.at(index) && *this->at(index) == *mappedList.at(index);
            }).length() == this->length();
    }
    bool operator!=(MappedList& mappedList) { return !(*this == mappedList); }
    template <typename T = IndexType, typename std::enable_if<!std::is_arithmetic<T>::value, int>::type = 0>
    ValueType& operator[](const int& index) {
        // TODO(0): proper handling of []
        return this->$list[index];
    }
    ValueType& operator[](const IndexType& index) {
        // TODO(0): proper handling of []
        return this->$map[index];
    }
    MappedList& operator+=(MappedList& mappedList) { return this->add(mappedList); }
    MappedList operator+(MappedList& mappedList) { return MappedList().add(*this).add(mappedList); }
    s11n$defineInline({
        ar & this->$list;
        ar & this->$map;
    });
}
godmode_foundation_types_$$