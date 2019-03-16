/*
 * FFTSampling.h
 *
 *  Created on: Mar 10, 2019
 *      Author: jan
 */

#ifndef APPLICATION_USER_FFTSAMPLING_H_
#define APPLICATION_USER_FFTSAMPLING_H_

#include <stdint.h>

typedef enum {
	FFT_WINDOW_RECTANGLE,
	FFT_WINDOW_HANN,
	FFT_WINDOW_HAMMING,
	FFT_WINDOW_FLATTOP,
} fft_window_t;

uint32_t FFT_take_sample(uint32_t points, fft_window_t window);
void fft_spi_mem_test();

#endif /* APPLICATION_USER_FFTSAMPLING_H_ */
