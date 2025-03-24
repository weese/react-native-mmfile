///
/// JHybridMmfilePlatformContextSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "JHybridMmfilePlatformContextSpec.hpp"



#include <string>
#include <optional>

namespace margelo::nitro::mmfile {

  jni::local_ref<JHybridMmfilePlatformContextSpec::jhybriddata> JHybridMmfilePlatformContextSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridMmfilePlatformContextSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridMmfilePlatformContextSpec::initHybrid),
    });
  }

  size_t JHybridMmfilePlatformContextSpec::getExternalMemorySize() noexcept {
    static const auto method = javaClassStatic()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  

  // Methods
  std::string JHybridMmfilePlatformContextSpec::getBaseDirectory() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JString>()>("getBaseDirectory");
    auto __result = method(_javaPart);
    return __result->toStdString();
  }
  std::optional<std::string> JHybridMmfilePlatformContextSpec::getAppGroupDirectory() {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<jni::JString>()>("getAppGroupDirectory");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toStdString()) : std::nullopt;
  }

} // namespace margelo::nitro::mmfile
