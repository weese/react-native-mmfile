require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "NitroMmfile"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :ios => min_ios_version_supported, :visionos => 1.0 }
  s.source       = { :git => "https://github.com/mrousavy/nitro.git", :tag => "#{s.version}" }

  s.source_files = [
    # Implementation (Swift)
    "ios/**/*.{swift}",
    # Autolinking/Registration (Objective-C++)
    "ios/**/*.{m,mm}",
    # Implementation (C++ objects)
    "cpp/**/*.{hpp,cpp}",
  ]

  s.pod_target_xcconfig = {
    # Ensure only ARM64 builds (iOS devices, not Intel simulators)
    "VALID_ARCHS[sdk=iphoneos*]" => "arm64",
    "VALID_ARCHS[sdk=iphonesimulator*]" => "",

    # Ensure correct architecture for iOS
    "ARCHS[sdk=iphoneos*]" => "arm64",
    "ARCHS[sdk=iphonesimulator*]" => "",

    # C++ compiler flags, mainly for folly.
    "GCC_PREPROCESSOR_DEFINITIONS" => "$(inherited) FOLLY_NO_CONFIG FOLLY_CFG_NO_COROUTINES",

    # Enforce armv8-a+crypto optimizations only on real iOS devices
    "OTHER_CPLUSPLUSFLAGS[sdk=iphoneos*]" => "$(inherited) -march=armv8-a+crypto",
    "OTHER_CPLUSPLUSFLAGS[sdk=iphonesimulator*]" => "$(inherited)"
  }

  load 'nitrogen/generated/ios/NitroMmfile+autolinking.rb'
  add_nitrogen_files(s)

  s.dependency 'React-jsi'
  s.dependency 'React-callinvoker'
  install_modules_dependencies(s)
end
