#pragma once

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/boost.serialization.h>
#ifndef serialization$
    #define s11n$export(...) /* 999 */
    #define s11n$exportAbstract(...) /* 999 */
    #define s11n$exportImplementation(...) /* 999 */
    #define s11n$instantiate(...) /* 999 */
    #define s11n$declare() /* 999 */
    #define s11n$declareSplit() /* 999 */
    #define s11n$defineInline(body) /* 999 */
    #define s11n$defineInlineSplit(saveBody, loadBody) /* 999 */
    #define s11n$define(className, body) /* 999 */
    #define s11n$defineSplit(className, saveBody, loadBody) /* 999 */
    #define s11n$defineTemplated(T, className, body) /* 999 */
    #define s11n$defineTemplatedSplit(T, className, saveBody, loadBody) /* 999 */
    #define s11n$private$defineSave(className, bod) /* 999 */
    #define s11n$private$defineLoad(className, body) /* 999 */
    #define s11n$private$defineMethod(className, methodName, body) /* 999 */
    #define s11n$private$defineConstMethod(className, methodName, body) /* 999 */
    #define s11n$private$defineTemplatedSave(T, className, body) /* 999 */
    #define s11n$private$defineTemplatedLoad(T, className, body) /* 999 */
#else
#define s11n$export(...) BOOST_CLASS_EXPORT_KEY(__VA_ARGS__)
#define s11n$exportAbstract(...) BOOST_SERIALIZATION_ASSUME_ABSTRACT(__VA_ARGS__)
#define s11n$exportImplementation(...) BOOST_CLASS_EXPORT_IMPLEMENT(__VA_ARGS__)
#define s11n$instantiate(...) \
    template void __VA_ARGS__::serialize<boost::archive::binary_iarchive>(boost::archive::binary_iarchive & ar, const unsigned int version); \
    template void __VA_ARGS__::serialize<boost::archive::binary_oarchive>(boost::archive::binary_oarchive & ar, const unsigned int version); \
    template void __VA_ARGS__::serialize<boost::archive::text_iarchive>(boost::archive::text_iarchive & ar, const unsigned int version); \
    template void __VA_ARGS__::serialize<boost::archive::text_oarchive>(boost::archive::text_oarchive & ar, const unsigned int version);
#define s11n$declare() \
    private: friend class boost::serialization::access; \
        template <class Archive> void serialize(Archive& ar, const unsigned int version);
#define s11n$declareSplit() \
    private: friend class boost::serialization::access; \
        template <class Archive> void serialize(Archive& ar, const unsigned int version); \
        template <class Archive> void save(Archive& ar, const unsigned int version) const; \
        template <class Archive> void load(Archive& ar, const unsigned int version);
#define s11n$defineInline(body) \
    private: friend class boost::serialization::access; \
        template <class Archive> void serialize(Archive& ar, const unsigned int version) { body }
#define s11n$defineInlineSplit(saveBody, loadBody) \
    private: friend class boost::serialization::access; \
        template <class Archive> void serialize(Archive& ar, const unsigned int version) { \
            boost::serialization::split_member(ar, *this, version); } \
        template <class Archive> void save(Archive& ar, const unsigned int version) const { saveBody } \
        template <class Archive> void load(Archive& ar, const unsigned int version) { loadBody }
#define s11n$private$defineMethod(className, methodName, body) \
    template <class Archive> void className::methodName(Archive& ar, const unsigned int version) { body }
#define s11n$private$defineConstMethod(className, methodName, body) \
    template <class Archive> void className::methodName(Archive& ar, const unsigned int version) const { body }
#define s11n$defineTemplatedMethod(T, className, methodName, body) T s11n$private$defineMethod(className, methodName, body);
#define s11n$defineTemplatedConstMethod(T, className, methodName, body) T s11n$private$defineConstMethod(className, methodName, body);
#define s11n$define(className, body) s11n$private$defineMethod(className, serialize, body);
#define s11n$private$defineSave(className, body) s11n$private$defineConstMethod(className, save, body);
#define s11n$private$defineLoad(className, body) s11n$private$defineMethod(className, load, body);
#define s11n$defineSplit(className, saveBody, loadBody) \
    template <class Archive> void className::serialize(Archive& ar, const unsigned int version) { \
        boost::serialization::split_member(ar, *this, version); \
    }; s11n$private$defineSave(className, saveBody); s11n$private$defineLoad(className, loadBody);
#define s11n$defineTemplated(T, className, body) s11n$defineTemplatedMethod(T, className, serialize, body);
#define s11n$private$defineTemplatedSave(T, className, body) s11n$defineTemplatedConstMethod(T, className, save, body);
#define s11n$private$defineTemplatedLoad(T, className, body) s11n$defineTemplatedMethod(T, className, load, body);
#define s11n$defineTemplatedSplit(T, className, saveBody, loadBody) \
    T template <class Archive> void className::serialize(Archive& ar, const unsigned int version) { \
        boost::serialization::split_member(ar, *this, version); \
    }; s11n$private$defineTemplatedSave(T, className, saveBody); s11n$private$defineTemplatedLoad(T, className, loadBody);
#endif