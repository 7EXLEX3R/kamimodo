#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/std.containers.h>
#include <godmode.foundation/serialization/Serialization.h>
#include <godmode.foundation/types/Function.h>
#include <godmode.foundation/types/InitializerList.h>
#include <godmode.foundation/types/Json_$.h>
#include <godmode.foundation/types/String_$.h>
#include <godmode.foundation/types/DefaultValue.h>

godmode_foundation_types_$
template <
    class ValueType,
    class ValueAccessType = typename std::conditional <
        std::is_pointer<ValueType>::value,
        ValueType,
        ValueType*
    >::type
> class List { $
    using std_list = std::deque<ValueType>;
    using ValueTypeInitializerList = InitializerList<ValueType>;
    std_list $list;
    constructor(List() {})
    constructor(List(std_list& list) { this->add(list); })
    constructor(List(ValueTypeInitializerList initList) { this->add(initList); })
    constructor(List(JsonValue& json) { this->add(json); })
    int length() { return this->$list.size(); }
    bool includes(ValueType item) { return this->indexOf(item) != -1; }
    int indexOf(const ValueType& item,
        Function<bool(ValueType a, ValueType b)> comparator = [](ValueType a, ValueType b) { return a == b; }) {
        for (int index = 0; index < this->$list.size(); index++)
            if (comparator(item, this->$list[index]))
                return index;
        return -1;
    }
    ValueAccessType at(int index, bool allowNegative = true) {
        if (allowNegative && index < 0)
            index = this->length() + index;
        if (index >= 0 && index < this->length())
            return this->pick(index);
        return nullptr;
    }
    ValueAccessType front() { return this->at(0); }
    ValueAccessType back() { return this->at(-1); }
    List& add(ValueType item) {
        this->$list.push_back(item);
        return *this;
    }
    List& add(List& list) {
        this->insert(list, this->length());
        return *this;
    }
    List& add(std_list& list) {
        this->insert(list, this->length());
        return *this;
    }
    List& add(ValueTypeInitializerList list) {
        this->insert(list, this->length());
        return *this;
    }
    List& add(JsonValue& json) {
        for (int i = 0; i < json.size(); i++)
            if (json[i].isString())
                this->add(json[i].asString());
            else
                this->add(json[i].asDouble());
        return *this;
    }
    List& insert(ValueType item, int index) {
        this->$list.insert(this->$list.begin() + index, item);
        return *this;
    }
    List& insert(List list, int index) {
        this->$list.insert(this->$list.begin() + index, list.$list.begin(), list.$list.end());
        return *this;
    }
    List& insert(std_list& list) {
        this->$list.insert(this->$list.begin() + index, list.begin(), list.end());
        return *this;
    }
    List& insert(ValueTypeInitializerList init, int index) {
        this->$list.insert(this->$list.begin() + index, init.begin(), init.end());
        return *this;
    }
    List& unshift(ValueType item) {
        this->$list.insert(this->$list.begin(), item);
        return *this;
    }
    List& unshift(List<ValueType>& list) {
        this->insert(list, 0);
        return *this;
    }
    ValueAccessType shift() {
        ValueAccessType item = this->at(0);
        if (item) {
            this->setBuffer(item);
            this->remove(item);
            return this->getBuffer();
        }
        return nullptr;
    }
    ValueAccessType pop() {
        ValueAccessType item = this->at(-1);
        if (item) {
            this->setBuffer(item);
            this->remove(item);
            return this->getBuffer();
        }
        return nullptr;
    }
    ValueAccessType removeAt(int index, bool _delete = false) {
        if (index < 0 && index >= this->length()) {}
        ValueAccessType item = this->at(index, false);
        if (item) {
            this->setBuffer(item);
            this->$list.erase(this->$list.begin() + index);
            this->safeDelete(item, _delete);
            return this->getBuffer();
        }
        return item;
    }
    List& remove(ValueType item, bool _delete = false) {
        this->removeAt(this->indexOf(item), _delete);
        return *this;
    }
    List& remove(ValueType* item, bool _delete = false) {
        this->removeAt(this->indexOf(*item), _delete);
        return *this;
    }
    List& clear(bool _delete = false) {
        for (int i = this->length() - 1; i >= 0; i--) this->removeAt(i, _delete);
        return *this;
    }
    ValueAccessType find(Function<bool(const ValueType& item)> predicate) {
        for (int index = 0; index < this->$list.size(); index++)
            if (predicate(this->$list[index]))
                return this->at(index);
        return nullptr;
    }
    ValueAccessType findLast(Function<bool(const ValueType& item)> predicate) {
        for (int index = this->$list.size() - 1; index >= 0; index--)
            if (predicate(this->$list[index]))
                return this->at(index);
        return nullptr;
    }
    List& sort(Function<bool(ValueType& a, ValueType& b)> comparator = [](ValueType a, ValueType b) { return a < b; }) {
        std::sort(this->$list.begin(), this->$list.end(), comparator);
        return *this;
    }
    List& forEach(Function<void(const ValueType& item, int index)> handler) {
        for (int index = 0; index < this->$list.size(); index++)
            handler(this->$list[index], index);
        return *this;
    }
    List& forEach(Function<void(const ValueType& item)> handler) {
        for (int index = 0; index < this->$list.size(); index++)
            handler(this->$list[index]);
        return *this;
    }
    List filter(Function<bool(const ValueType& item, int index)> predicate) const {
        List<ValueType> result;
        for (int index = 0; index < this->$list.size(); index++)
            if (predicate(this->$list[index], index))
                result.add(this->$list[index]);
        return result;
    }
    List filter(Function<bool(const ValueType& item)> predicate) const {
        List<ValueType> result;
        for (int index = 0; index < this->$list.size(); index++)
            if (predicate(this->$list[index]))
                result.add(this->$list[index]);
        return result;
    }
    template <typename ResultType>
    List<ResultType, ResultType*> map(Function<ResultType(const ValueType& item, int index)> mapper) const {
        List<ResultType> result;
        for (int index = 0; index < this->$list.size(); index++)
            result.add(mapper(this->$list[index], index));
        return result;
    }
    template <typename ResultType>
    List<ResultType, ResultType*> map(Function<ResultType(const ValueType& item)> mapper) const {
        List<ResultType> result;
        for (int index = 0; index < this->$list.size(); index++)
            result.add(mapper(this->$list[index]));
        return result;
    }
    template <typename ResultType>
    ResultType reduce(Function<ResultType(ResultType accumulator, const ValueType& item, int index)> reducer, ResultType initial) const {
        ResultType accumulator = initial;
        for (int index = 0; index < this->$list.size(); index++)
            accumulator = reducer(accumulator, this->$list[index], index);
        return accumulator;
    }
    template <typename ResultType>
    ResultType reduce(Function<ResultType(ResultType accumulator, const ValueType& item)> reducer, ResultType initial) const {
        ResultType accumulator = initial;
        for (int index = 0; index < this->$list.size(); index++)
            accumulator = reducer(accumulator, this->$list[index]);
        return accumulator;
    }
    String join(String separator = "") {
        ValueType collector;
        if (this->length() == 0)
            return collector;
        collector = *this->at(0);
        for (int i = 1; i < this->length(); i++)
            collector += separator + *this->at(i);
        return collector;
    }
    List slice(int beginIndex, int endIndex = INT_MAX) {
        List result;
        int len = static_cast<int>(this->$list.size());
        if (beginIndex < 0)
            beginIndex = len + beginIndex;
        if (endIndex < 0)
            endIndex = len + endIndex;
        beginIndex = std::max(0, std::min(beginIndex, len));
        endIndex = std::max(0, std::min(endIndex, len));
        if (beginIndex >= endIndex)
            return result;
        result.$list.insert(result.$list.end(), this->$list.begin() + beginIndex, this->$list.begin() + endIndex);
        return result;
    }
    static List generate(int count, Function<ValueType(const int&)> mapper) {
        List result;
        for (int i = 0; i < count; i++)
            result.add(mapper(i));
        return result;
    }
    List& operator=(List& list) { return this->clear().add(list); }
    List& operator=(JsonValue& json) { return this->clear().add(json); }
    bool operator==(List& list) {
        return this->length() == list.length()
            && this->filter([this, &list](const ValueType& item, int index) {
                return *this->at(index) == *list.at(index);
            }).length() == this->length();
    }
    bool operator!=(List& list) { return !(*this == list); }
    ValueType& operator[](int index) { return this->$list[index]; }
    List& operator+=(List& list) { return this->add(list); }
    List operator+(List& list) { return List().add(*this).add(list); }
protected:
    static bool defaultValueComparator(ValueType a, ValueType b) { return a == b; }
    static bool defaultSortComparator(ValueType a, ValueType b) { return a < b; }
private:
    ValueType $buffer = DefaultValue<ValueType>::get();
    template <typename T = ValueType>
    typename std::enable_if<std::is_pointer<T>::value, T>::type pick(int index) {
        return this->$list[index];
    }
    template <typename T = ValueType>
    typename std::enable_if<!std::is_pointer<T>::value, T*>::type pick(int index) {
        return &this->$list[index];
    }
    template <typename T = ValueType, typename std::enable_if<std::is_pointer<T>::value, int>::type = 0>
    void setBuffer(ValueAccessType item) {
        this->$buffer = item;
    }
    template <typename T = ValueType, typename std::enable_if<!std::is_pointer<T>::value, int>::type = 0>
    void setBuffer(ValueAccessType item) {
        this->$buffer = *item;
    }
    template <typename T = ValueType, typename std::enable_if<std::is_pointer<T>::value, int>::type = 0>
    ValueAccessType getBuffer() {
        return this->$buffer;
    }
    template <typename T = ValueType, typename std::enable_if<!std::is_pointer<T>::value, int>::type = 0>
    ValueAccessType getBuffer() {
        return &this->$buffer;
    }
    template <typename T = ValueType>
    typename std::enable_if<std::is_pointer<T>::value, void>::type safeDelete(ValueAccessType item, bool _delete) {
        if (_delete)
            delete item;
    }
    template <typename T = ValueType>
    typename std::enable_if<!std::is_pointer<T>::value, void>::type safeDelete(ValueAccessType, bool) {}
    s11n$defineInline({
        ar & this->$list;
    });
}
godmode_foundation_types_$$