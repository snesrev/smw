#ifndef _include_guard_nanotime_
#define _include_guard_nanotime_

/*
 * You can choose this license, if possible in your jurisdiction:
 *
 * Unlicense
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or distribute
 * this software, either in source code form or as a compiled binary, for any
 * purpose, commercial or non-commercial, and by any means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors of
 * this software dedicate any and all copyright interest in the software to the
 * public domain. We make this dedication for the benefit of the public at
 * large and to the detriment of our heirs and successors. We intend this
 * dedication to be an overt act of relinquishment in perpetuity of all present
 * and future rights to this software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 *
 *
 * Alternative license choice, if works can't be directly submitted to the
 * public domain in your jurisdiction:
 *
 * The MIT License (MIT)
 *
 * Copyright © 2022 Brandon McGriff <nightmareci@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#if defined(_MSC_VER)
	#if (_MSC_VER < 1600)
		#error "Current Visual Studio version is not at least Visual Studio 2010, the nanotime library requires at least 2010."
	#endif
#elif defined(__cplusplus)
	#if (__cplusplus < 201103L)
		#error "Current C++ standard is not at least C++11, the nanotime library requires at least C++11."
	#endif
#elif defined(__STDC_VERSION__)
	#if (__STDC_VERSION__ < 199901L)
		#error "Current C standard is not at least C99, the nanotime library requires at least C99."
	#endif
#else
	#error "Current C or C++ standard is unknown, the nanotime library requires stdint.h and stdbool.h to be available (C99 or higher, C++11 or higher, Visual Studio 2010 or higher)."
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Implementor's note: This library directly uses Win32 APIs both for MSVC and
 * MinGW GCC, as they work for both, and produce better behavior in MinGW
 * builds. Detection of them is accomplished via checking if _WIN32 is defined,
 * as it's defined in both MSVC and MinGW GCC. Though it's convenient to have
 * UNIX-like APIs on Windows provided by MinGW, they just aren't as good as
 * directly using Win32 APIs on Windows.
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define NANOTIME_NSEC_PER_SEC UINT64_C(1000000000)

#ifndef NANOTIME_ONLY_STEP

/*
 * Returns the current time since some unspecified epoch. With the exception of
 * the standard C11 implementation and non-Apple/Mach kernel POSIX
 * implementation when neither CLOCK_MONOTONIC_RAW nor CLOCK_MONOTONIC are
 * available, the time values monotonically increase, so they're not equivalent
 * to calendar time (i.e., no leap seconds are accounted for, etc.). Calendar
 * time has to be used as a last resort sometimes, as monotonic time isn't
 * always available.
 */
uint64_t nanotime_now();

/*
 * Returns the maximum possible timestamp value. Use of this value is required
 * to properly handle overflow of timestamp values, such as when calculating the
 * interval between a time value before overflow and the next time value after
 * overflow.
 */
uint64_t nanotime_now_max();

/*
 * Sleeps the current thread for the requested count of nanoseconds. The slept
 * duration may be less than, equal to, or greater than the time requested.
 */
void nanotime_sleep(uint64_t nsec_count);

#endif

#ifndef NANOTIME_ONLY_STEP

/*
 * The yield function is provided for some platforms, but in the case of
 * unknown platforms, the function is defined as a no-op.
 */

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#define nanotime_yield() YieldProcessor()
#define NANOTIME_YIELD_IMPLEMENTED
#elif (defined(__unix__) || defined(__APPLE__)) && defined(_POSIX_VERSION) && (_POSIX_VERSION >= 200112L)
#include <sched.h>
#define nanotime_yield() (void)sched_yield()
#define NANOTIME_YIELD_IMPLEMENTED
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_THREADS__)
#include <threads.h>
#define nanotime_yield() thrd_yield()
#define NANOTIME_YIELD_IMPLEMENTED
#elif defined(__cplusplus)
extern void (* const nanotime_yield)();
#elif defined(__SWITCH__)
#include <switch.h>
#define nanotime_yield() svcSleepThread(YieldType_ToAnyThread)
#define NANOTIME_YIELD_IMPLEMENTED
#else
#define nanotime_yield()
#define NANOTIME_YIELD_NOP
#define NANOTIME_YIELD_IMPLEMENTED
#endif

#endif

/*
 * Calculates the time interval between two nanosecond time values, correctly
 * handling the case when the end time value overflows past max. You should
 * probably use this function when calculating time intervals, as not all
 * platforms' maximum timestamp value is UINT64_MAX, which is required for the
 * trivial "end - start" formula for interval calculation to work as expected.
 */
uint64_t nanotime_interval(const uint64_t start, const uint64_t end, const uint64_t max);

typedef struct nanotime_step_data {
	uint64_t sleep_duration;
	uint64_t now_max;
	uint64_t (* now)();
	void (* sleep)(uint64_t nsec_count);

 	#ifdef __APPLE__
	uint64_t overhead_numer;
	uint64_t overhead_denom;
	uint64_t backoff;
	#endif
	uint64_t zero_sleep_duration;
	uint64_t accumulator;
	uint64_t sleep_point;
} nanotime_step_data;

/*
 * Initializes the nanotime precise fixed timestep object. Call immediately
 * before entering the loop using the stepper object.
 */
void nanotime_step_init(nanotime_step_data* const stepper, const uint64_t sleep_duration, const uint64_t now_max, uint64_t (* const now)(), void (* const sleep)(uint64_t nsec_count));

/*
 * Does one step of sleeping for a fixed timestep logic update cycle. It makes
 * a best-attempt at a precise delay per iteration, but might skip a cycle of
 * sleeping if skipping sleeps is required to catch up to the correct
 * wall-clock time. Returns true if a sleep up to the latest target sleep end
 * time occurred, otherwise returns false in the case of a sleep step skip.
 */
bool nanotime_step(nanotime_step_data* const stepper);

#if !defined(NANOTIME_ONLY_STEP) && defined(NANOTIME_IMPLEMENTATION)

/*
 * Non-portable, platform-specific implementations are first. If none of them
 * match the current platform, the standard C/C++ versions are used as a last
 * resort.
 */

#ifdef _WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>

#ifndef NANOTIME_NOW_IMPLEMENTED
uint64_t nanotime_now() {
	static uint64_t scale = UINT64_C(0);
	static bool multiply;
	if (scale == 0u) {
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		if (frequency.QuadPart < NANOTIME_NSEC_PER_SEC) {
			scale = NANOTIME_NSEC_PER_SEC / frequency.QuadPart;
			multiply = true;
		}
		else {
			scale = frequency.QuadPart / NANOTIME_NSEC_PER_SEC;
			multiply = false;
		}
	}
	LARGE_INTEGER performanceCount;
	QueryPerformanceCounter(&performanceCount);
	if (multiply) {
		return performanceCount.QuadPart * scale;
	}
	else {
		return performanceCount.QuadPart / scale;
	}
}
#define NANOTIME_NOW_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_MAX_IMPLEMENTED
uint64_t nanotime_now_max() {
	static uint64_t now_max;
	if (now_max == UINT64_C(0)) {
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		if (frequency.QuadPart < NANOTIME_NSEC_PER_SEC) {
			now_max = UINT64_MAX * (NANOTIME_NSEC_PER_SEC / frequency.QuadPart);
		}
		else {
			now_max = UINT64_MAX / (frequency.QuadPart / NANOTIME_NSEC_PER_SEC);
		}
	}
	return now_max;
}
#define NANOTIME_NOW_MAX_IMPLEMENTED
#endif

#ifndef NANOTIME_SLEEP_IMPLEMENTED
void nanotime_sleep(uint64_t nsec_count) {
	LARGE_INTEGER dueTime;

	if (nsec_count < UINT64_C(100)) {
		/*
		 * Allows the OS to schedule another process for a single time
		 * slice. Better than a delay of 0, which immediately returns
		 * with no actual non-CPU-hogging delay. The time-slice-yield
		 * behavior is specified in Microsoft's Windows documentation.
		 */
		SleepEx(0UL, FALSE);
	}
	else {
		HANDLE timer = NULL;
		if (
#ifdef CREATE_WAITABLE_TIMER_HIGH_RESOLUTION
			/*
			 * Requesting a high resolution timer can make quite the
			 * difference, so always request high resolution if available. It's
			 * available in Windows 10 1803 and above. This arrangement of
			 * building it if the build system supports it will allow the
			 * executable to use high resolution if available on a user's
			 * system, but revert to low resolution if the user's system
			 * doesn't support high resolution.
			 */
			(timer = CreateWaitableTimerEx(NULL, NULL, CREATE_WAITABLE_TIMER_HIGH_RESOLUTION, TIMER_ALL_ACCESS)) == NULL &&
#endif
			(timer = CreateWaitableTimer(NULL, TRUE, NULL)) == NULL
		) {
			return;
		}

		dueTime.QuadPart = -(LONGLONG)(nsec_count / UINT64_C(100));

		SetWaitableTimer(timer, &dueTime, 0L, NULL, NULL, FALSE);
		WaitForSingleObject(timer, INFINITE);

		CloseHandle(timer);
	}
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#endif

#if defined(__APPLE__) || defined(__MACH__)

#ifndef NANOTIME_NOW_IMPLEMENTED
// The current platform is some Apple operating system, or at least uses some
// Mach kernel. The POSIX implementation below using clock_gettime works on at
// least Apple platforms, though this version using Mach functions has lower
// overhead.
#include <mach/mach_time.h>
uint64_t nanotime_now() {
	static mach_timebase_info_data_t info = { 0 };
	if (info.denom == UINT32_C(0)) {
		const kern_return_t status = mach_timebase_info(&info);
		assert(status == KERN_SUCCESS);
		if (status != KERN_SUCCESS) {
			return UINT64_C(0);
		}
	}
	return (mach_absolute_time() * info.numer) / info.denom;
}
#define NANOTIME_NOW_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_MAX_IMPLEMENTED
#include <mach/mach_time.h>
uint64_t nanotime_now_max() {
	static uint64_t now_max = UINT64_C(0);
	if (now_max == UINT64_C(0)) {
		mach_timebase_info_data_t info;
		const kern_return_t status = mach_timebase_info(&info);
		assert(status == KERN_SUCCESS);
		if (status != KERN_SUCCESS) {
			return UINT64_C(0);
		}
		else {
			now_max = UINT64_MAX / info.denom;
		}
	}
	return now_max;
}
#define NANOTIME_NOW_MAX_IMPLEMENTED
#endif

#endif

#if defined(__unix__) && defined(_POSIX_VERSION) && (_POSIX_VERSION >= 199309L) && !defined(NANOTIME_NOW_IMPLEMENTED)
// Current platform is some version of POSIX, that might have clock_gettime.
#include <unistd.h>
#include <time.h>
#include <errno.h>
uint64_t nanotime_now() {
	struct timespec now;
	const int status = clock_gettime(
		#if defined(CLOCK_MONOTONIC_RAW)
		// Monotonic raw is more precise, but not always available. For the
		// sorts of applications this code is intended for, mainly soft real
		// time applications such as game programming, the subtle
		// inconsistencies of it vs. monotonic aren't an issue.
		CLOCK_MONOTONIC_RAW
		#elif defined(CLOCK_MONOTONIC)
		// Monotonic is quite good, and widely available, but not as precise as
		// monotonic raw, so it's only used if required.
		CLOCK_MONOTONIC
		#else
		// Realtime isn't fully correct, as it's calendar time, but is even more
		// widely available than monotonic. Monotonic is only unavailable on
		// very old platforms though, so old they're likely unused now (as of
		// last editing this, 2023).
		CLOCK_REALTIME
		#endif
	, &now);
	assert(status == 0 || (status == -1 && errno != EOVERFLOW));
	if (status == 0 || (status == -1 && errno != EOVERFLOW)) {
		return (uint64_t)now.tv_sec * NANOTIME_NSEC_PER_SEC + (uint64_t)now.tv_nsec;
	}
	else {
		return UINT64_C(0);
	}
}
#define NANOTIME_NOW_IMPLEMENTED

#endif

#if (defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__MINGW32__) || defined(__MINGW64__)) && !defined(NANOTIME_SLEEP_IMPLEMENTED)
#include <unistd.h>
#include <time.h>
#include <errno.h>
void nanotime_sleep(uint64_t nsec_count) {
	const struct timespec req = {
		.tv_sec = (time_t)(nsec_count / NANOTIME_NSEC_PER_SEC),
		.tv_nsec = (long)(nsec_count % NANOTIME_NSEC_PER_SEC)
	};
#ifndef NDEBUG
	const int status =
#endif
	nanosleep(&req, NULL);
	assert(status == 0 || (status == -1 && errno != EINVAL));
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#if defined(__vita__)
#ifndef NANOTIME_SLEEP_IMPLEMENTED
#include <psp2/kernel/processmgr.h>
void nanotime_sleep(uint64_t nsec_count) {
	sceKernelDelayThreadCB(nsec_count / UINT64_C(1000));
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_IMPLEMENTED
#include <psp2/kernel/processmgr.h>
uint64_t nanotime_now() {
	return sceKernelGetProcessTimeWide() * UINT64_C(1000);
}
#define NANOTIME_NOW_IMPLEMENTED
#endif
#endif

#ifdef __EMSCRIPTEN__
#ifndef NANOTIME_SLEEP_IMPLEMENTED
#include <emscripten.h>
/*
 * NOTE: You *must* have asyncify enabled in the Emscripten build (pass
 * -sASYNCIFY to the compiler/linker) or sleeping won't work.
 */
void nanotime_sleep(uint64_t nsec_count) {
	emscripten_sleep(nsec_count / UINT64_C(1000000));
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_IMPLEMENTED
#include <emscripten.h>
uint64_t nanotime_now() {
	const double now = emscripten_get_now();
	return (uint64_t)now * UINT64_C(1000000);
}
#define NANOTIME_NOW_IMPLEMENTED
#endif
#endif

#ifdef __SWITCH__
#ifndef NANOTIME_SLEEP_IMPLEMENTED
#include <switch.h>
void nanotime_sleep(uint64_t nsec_count) {
	if (nsec_count > INT64_MAX) {
		svcSleepThread(INT64_MAX);
	}
	else {
		svcSleepThread((s64)nsec_count);
	}
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_IMPLEMENTED
#define NANOTIME_NOW_IMPLEMENTED
#include <switch.h>
uint64_t nanotime_now() {
	return svcGetSystemTick();
}
#define NANOTIME_NOW_IMPLEMENTED
#endif
#endif


#ifndef NANOTIME_NOW_IMPLEMENTED
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#include <time.h>
uint64_t nanotime_now() {
	struct timespec now;
	const int status = timespec_get(&now, TIME_UTC);
	assert(status == TIME_UTC);
	if (status == TIME_UTC) {
		return (uint64_t)now.tv_sec * NANOTIME_NSEC_PER_SEC + (uint64_t)now.tv_nsec;
	}
	else {
		return UINT64_C(0);
	}
}
#define NANOTIME_NOW_IMPLEMENTED
#endif
#endif

#ifndef NANOTIME_SLEEP_IMPLEMENTED
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_THREADS__)
#include <threads.h>
void nanotime_sleep(uint64_t nsec_count) {
	const struct timespec req = {
		.tv_sec = (time_t)(nsec_count / NANOTIME_NSEC_PER_SEC),
		.tv_nsec = (long)(nsec_count % NANOTIME_NSEC_PER_SEC)
	};
	const int status = thrd_sleep(&req, NULL);
	assert(status == 0 || status == -1);
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif
#endif

#endif

#ifdef __cplusplus
}
#endif

#if !defined(NANOTIME_ONLY_STEP) && defined(NANOTIME_IMPLEMENTATION) && defined(__cplusplus)

#if !defined(NANOTIME_YIELD_IMPLEMENTED)
#include <thread>
extern "C" void (* const nanotime_yield)() = std::this_thread::yield;
#define NANOTIME_YIELD_IMPLEMENTED
#endif

#ifndef NANOTIME_NOW_IMPLEMENTED
#include <cstdint>
#include <chrono>
extern "C" uint64_t nanotime_now() {
	return static_cast<uint64_t>(
		std::chrono::time_point_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now()
		).time_since_epoch().count()
	);
}
#define NANOTIME_NOW_IMPLEMENTED
#endif

#ifndef NANOTIME_SLEEP_IMPLEMENTED
#include <cstdint>
#include <thread>
#include <exception>
extern "C" void nanotime_sleep(uint64_t nsec_count) {
	try {
		std::this_thread::sleep_for(std::chrono::nanoseconds(nsec_count));
	}
	catch (std::exception e) {
	}
}
#define NANOTIME_SLEEP_IMPLEMENTED
#endif

#endif

#if !defined(NANOTIME_ONLY_STEP) && defined(NANOTIME_IMPLEMENTATION) 

#ifndef NANOTIME_NOW_IMPLEMENTED
#error "Failed to implement nanotime_now (try using C11 with C11 threads support or C++11)."
#endif

#ifndef NANOTIME_SLEEP_IMPLEMENTED
#error "Failed to implement nanotime_sleep (try using C11 with C11 threads support or C++11)."
#endif

#endif

#ifdef NANOTIME_IMPLEMENTATION
#ifdef __cplusplus
extern "C" {
#endif

#ifndef NANOTIME_NOW_MAX_IMPLEMENTED
// Might not be correct on some platforms, but it's the best we can do as a last
// resort.
uint64_t nanotime_now_max() {
	return UINT64_MAX;
}
#define NANOTIME_NOW_MAX_IMPLEMENTED
#endif

uint64_t nanotime_interval(const uint64_t start, const uint64_t end, const uint64_t max) {
	assert(
		max > UINT64_C(0) &&
		start <= max &&
		end <= max
	);

	if (end >= start) {
		return end - start;
	}
	else {
		return end + (max - start) + UINT64_C(1);
	}
}

void nanotime_step_init(nanotime_step_data* const stepper, const uint64_t sleep_duration, const uint64_t now_max, uint64_t (* const now)(), void (* const sleep)(uint64_t nsec_count)) {
	assert(
		stepper != NULL &&
		sleep_duration > UINT64_C(0) &&
		now_max > UINT64_C(0) &&
		now != NULL &&
		sleep != NULL
	);

	stepper->sleep_duration = sleep_duration;
	stepper->now_max = now_max;
	stepper->now = now;
	stepper->sleep = sleep;

	const uint64_t start = now();
	nanotime_sleep(UINT64_C(0));
	stepper->zero_sleep_duration = nanotime_interval(start, now(), now_max);
	#ifdef __APPLE__
	stepper->overhead_numer = UINT64_C(1);
	stepper->overhead_denom = UINT64_C(1);
	stepper->backoff = UINT64_C(0);
	#endif
	stepper->accumulator = UINT64_C(0);

	// This should be last here, so the sleep point is close to what it
	// should be.
	stepper->sleep_point = now();
}

bool nanotime_step(nanotime_step_data* const stepper) {
	assert(stepper != NULL);

	bool slept;
	if (stepper->accumulator < stepper->sleep_duration) {
		const uint64_t total_sleep_duration = stepper->sleep_duration - stepper->accumulator;
		uint64_t current_sleep_duration = total_sleep_duration;
		const uint64_t shift = UINT64_C(4);

		#ifdef __APPLE__
		// Start with a big sleep. This helps reduce CPU/power use vs. many
		// shorter sleeps. Shorter sleeps are still done below, but this reduces
		// the number of shorter sleeps. It appears that the actually-slept
		// duration is roughly equal to the requested delay time multiplied by a
		// factor that remains relatively constant over the short run, greater
		// than 1.0, in testing on ARM macOS; such behavior doesn't appear to be
		// the case on all platforms, but is the case in testing on an M1 Mac.
		// By only setting the overhead factor when the sleep overshoots, it
		// levels off to a pretty stable value in a feedback loop, resulting in
		// the big sleep approaching a value that does as big as possible of a
		// big sleep while reducing overshoots.  Also, a "backoff" duration is
		// subtracted from the overhead factor-adjusted sleep duration, which
		// reduces the frequency of overshoots, while still maintaining the
		// desired longer sleep duration before the higher cost/higher precision
		// sleeping below; the backoff duration is also updated in a feedback
		// loop that causes it to approach a reasonably correct value.
		// TODO: This was carefully tuned to be well-behaved on Apple Silicon
		// M1, but hasn't been tested on any Intel Mac; test on an Intel Mac to
		// see if this algorithm is appropriate there, if not, special-case for
		// each CPU type.
		// TODO: Implement "initial big sleep" for other platforms; it really
		// does reduce wasted cycles regardless of platform. Or, if this
		// algorithm seems to work fine on other platforms, change it to be used
		// on all platforms, not just Apple's.
		uint64_t overhead_sleep_duration = (current_sleep_duration * stepper->overhead_numer) / stepper->overhead_denom;
		if (overhead_sleep_duration > stepper->backoff) {
			overhead_sleep_duration -= stepper->backoff;
		}
		else {
			stepper->backoff = UINT64_C(0);
		}
		const uint64_t overhead_start = stepper->now();
		stepper->sleep(overhead_sleep_duration);
		const uint64_t big_sleep_duration = nanotime_interval(overhead_start, stepper->now(), stepper->now_max);
		const uint64_t slept_so_far = nanotime_interval(stepper->sleep_point, stepper->now(), stepper->now_max);
		if (slept_so_far <= total_sleep_duration) {
			if (stepper->backoff >= total_sleep_duration - slept_so_far) {
				stepper->backoff -= total_sleep_duration - slept_so_far;
			}
			current_sleep_duration -= slept_so_far;
		}
		else {
			stepper->overhead_numer = overhead_sleep_duration;
			stepper->overhead_denom = big_sleep_duration > UINT64_C(0) ? big_sleep_duration : UINT64_C(1);
			if (stepper->backoff <= UINT64_MAX - slept_so_far - total_sleep_duration) {
				stepper->backoff += slept_so_far - total_sleep_duration;
			}
			if (stepper->overhead_numer > stepper->overhead_denom) {
				stepper->overhead_numer = UINT64_C(1);
				stepper->overhead_denom = UINT64_C(1);
			}
			goto step_end;
		}
		#endif

		// This has the flavor of Zeno's dichotomous paradox of motion, as it
		// successively divides the time remaining to sleep, but attempts to
		// stop short of the deadline to hopefully be able to precisely sleep up
		// to the deadline below this loop. The divisor is larger than two
		// though, as it produces better behavior, and seems to work fine in
		// testing on real hardware. This loop, and the one below, take the
		// assumption that sleep requests of the same amount are roughly equal;
		// by keeping track of the max of all the sleeps, the loops can be
		// broken out of when the remaining time is less than the max, allowing
		// the loop after this one to do shorter sleeps, with a corresponding
		// smaller max of the sleeps. The overshoot possible in the loop below
		// this one won't overshoot much, or in the best case won't overshoot so
		// the busyloop can finish up the sleep precisely.
		current_sleep_duration >>= shift;
		for (
			uint64_t max = stepper->zero_sleep_duration;
			nanotime_interval(stepper->sleep_point, stepper->now(), stepper->now_max) + max < total_sleep_duration && current_sleep_duration > UINT64_C(0);
			current_sleep_duration >>= shift
		) {
			max = stepper->zero_sleep_duration;
			uint64_t start;
			while (max < stepper->sleep_duration && nanotime_interval(stepper->sleep_point, start = stepper->now(), stepper->now_max) + max < total_sleep_duration) {
				stepper->sleep(current_sleep_duration);
				uint64_t slept_duration;
				if ((slept_duration = nanotime_interval(start, stepper->now(), stepper->now_max)) > max) {
					max = slept_duration;
				}
			}
		}

		{
			// After (hopefully) stopping short of the deadline by a small
			// amount, do small sleeps here to get closer to the deadline, but
			// again attempting to stop short by an even smaller amount. It's
			// best to do larger sleeps as done in the above loop, to reduce
			// CPU/power usage, as each sleep iteration has a CPU/power usage
			// cost.
			uint64_t max = stepper->zero_sleep_duration;
			uint64_t start;
			while (nanotime_interval(stepper->sleep_point, start = stepper->now(), stepper->now_max) + max < total_sleep_duration) {
				stepper->sleep(UINT64_C(0));
				if ((stepper->zero_sleep_duration = nanotime_interval(start, stepper->now(), stepper->now_max)) > max) {
					max = stepper->zero_sleep_duration;
				}
			}
		}

		#ifdef __APPLE__
		step_end:
		#endif
		{
			// Finally, do a busyloop to precisely sleep up to the
			// deadline. The code above this loop attempts to reduce the
			// remaining time to sleep to a minimum via process-yielding
			// sleeps, so the amount of time spent spinning here is
			// hopefully quite low.
			uint64_t current_time;
			uint64_t accumulated;
			while ((accumulated = nanotime_interval(stepper->sleep_point, current_time = stepper->now(), stepper->now_max)) < total_sleep_duration);

			stepper->accumulator += accumulated;
			stepper->sleep_point = current_time;
			slept = true;
		}
	}
	else {
		slept = false;
	}
	stepper->accumulator -= stepper->sleep_duration;
	return slept;
}

#ifdef __cplusplus
}
#endif
#endif

#endif /* _include_guard_nanotime_ */
