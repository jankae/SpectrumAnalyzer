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
	FFT_WINDOW_RECTANGLE = 0,
	FFT_WINDOW_HANN = 1,
	FFT_WINDOW_HAMMING = 2,
	FFT_WINDOW_FLATTOP = 3,
	FFT_WINDOW_MAX = 4,
} fft_window_t;

float FFT_take_sample(uint32_t points, fft_window_t window);
void fft_spi_test();

#endif /* APPLICATION_USER_FFTSAMPLING_H_ */
