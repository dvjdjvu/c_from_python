[app]

# (str) Title of your application
title = KivyTest

# (str) Package name
package.name = kivy_test

# (str) Package domain (needed for android/ios packaging)
package.domain = com.heattheatr

# (str) Source code where the main.py live
source.dir = .

# (list) Source files to include (let empty to include all the files)
source.include_exts = py,png,jpg,jpeg,ttf

# (list) Application version
version = 0.0.1

# (list) Application requirements
# comma separated e.g. requirements = sqlite3,kivy
requirements = python3, kivy

# (str) Custom source folders for requirements
# Sets custom source for any requirements with recipes
# requirements.source.kivy = ../../kivy
#requirements.source.libtest = lib/libtest

# (str) Supported orientation (one of landscape, sensorLandscape, portrait or all)
orientation = portrait

# (bool) Indicate if the application should be fullscreen or not
fullscreen = 1

# (list) Permissions
android.permissions = INTERNET,WRITE_EXTERNAL_STORAGE

# (int) Target Android API, should be as high as possible.
android.api = 28

# (int) Minimum API your APK will support.
android.minapi = 21

# (str) Android NDK version to use
android.ndk = 19c

# (bool) If True, then skip trying to update the Android sdk
# This can be useful to avoid excess Internet downloads or save time
# when an update is due and you just want to test/build your package
android.skip_update = False

# (bool) If True, then automatically accept SDK license
# agreements. This is intended for automation only. If set to False,
# the default, you will be shown the license when first running
# buildozer.
android.accept_sdk_license = True

# (str) The Android arch to build for, choices: armeabi-v7a, arm64-v8a, x86, x86_64
android.archs = arm64-v8a

# (list) Android additionnal libraries to copy into libs/armeabi
android.add_libs_arm64_v8a = %(source.dir)s/libs/libs_arm64_v8a/*.*
android.add_libs_armeabi_v7a = %(source.dir)s/libs/libs_armeabi-v7a/*.*

[buildozer]

# (int) Log level (0 = error only, 1 = info, 2 = debug (with command output))
log_level = 2

# (int) Display warning if buildozer is run as root (0 = False, 1 = True)
warn_on_root = 0

# (str) Path to build artifact storage, absolute or relative to spec file
build_dir = ./.buildozer

# (str) Path to build output (i.e. .apk, .ipa) storage
bin_dir = ./bin
