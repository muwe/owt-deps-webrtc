/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_RTC_BASE_ANNOTATIONS_H_
#define WEBRTC_RTC_BASE_ANNOTATIONS_H_

// Annotate a function indicating the caller must examine the return value.
// Use like:
//   int foo() RTC_WARN_UNUSED_RESULT;
// To explicitly ignore a result, cast to void.
// TODO(kwiberg): Remove when we can use [[nodiscard]] from C++17.
#if defined(__clang__)
#define RTC_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#elif defined(__GNUC__)
// gcc has a __warn_unused_result__ attribute, but you can't quiet it by
// casting to void, so we don't use it.
#define RTC_WARN_UNUSED_RESULT
#else
#define RTC_WARN_UNUSED_RESULT
#endif

// Macro to be used for switch-case fallthrough (required for enabling
// -Wimplicit-fallthrough warning on Clang).
#if defined(__clang__)
#define RTC_FALLTHROUGH() [[clang::fallthrough]]
#else
#define RTC_FALLTHROUGH() do { } while (0)
#endif

// Prevent the compiler from warning about an unused variable. For example:
//   int result = DoSomething();
//   assert(result == 17);
//   RTC_UNUSED(result);
// Note: In most cases it is better to remove the unused variable rather than
// suppressing the compiler warning.
#define RTC_UNUSED(x) static_cast<void>(x)

#endif  // WEBRTC_RTC_BASE_ANNOTATIONS_H_
