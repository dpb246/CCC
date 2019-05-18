#include <x86intrin.h>
#pragma GCC optimize("Ofast","sched-spec-load-dangerous","unroll-loops")//,"omit-frame-pointer","inline")
//#pragma GCC option("no-vzeroupper")//,"arch=native",)//,"tune=native"))
#pragma GCC target("avx2", "fma")
double multiply_matrices(double a[256][256], double b[256][256]) {
    //double answer = 0.0;
    double c[256][256] = {};
    int kb = 16;
    __m256d sumA_1, sumB_1, sumA_2, sumB_2, sumA_3, sumB_3, sumA_4, sumB_4;
    for (int kk = 0; kk < 256; kk += kb) {
        for (int i = 0; i < 256; i += 4) {
            for (int j = 0; j < 256; j += 8) {
                if (kk == 0) sumA_1 = sumB_1 = sumA_2 = sumB_2 = sumA_3 = sumB_3 = sumA_4 = sumB_4 = _mm256_setzero_pd();
                else {
                  sumA_1 = _mm256_load_pd(&c[i][j]);
                  sumB_1 = _mm256_load_pd(&c[i][j + 4]);
                  sumA_2 = _mm256_load_pd(&c[i+1][j]);
                  sumB_2 = _mm256_load_pd(&c[i+1][j + 4]);
                  sumA_3 = _mm256_load_pd(&c[i+2][j]);
                  sumB_3 = _mm256_load_pd(&c[i+2][j + 4]);
                  sumA_4 = _mm256_load_pd(&c[i+3][j]);
                  sumB_4 = _mm256_load_pd(&c[i+3][j + 4]);
                }
                for (int k = kk; k < kk+kb; k++) {
                    auto vecA_mat2 = _mm256_loadu_pd(&b[k][j]);
                    auto vecB_mat2 = _mm256_loadu_pd(&b[k][j + 4]);
                    auto bc_mat1_1 = _mm256_set1_pd(a[i][k]);
                    sumA_1 = _mm256_add_pd(sumA_1, _mm256_mul_pd(bc_mat1_1, vecA_mat2));
                    sumB_1 = _mm256_add_pd(sumB_1, _mm256_mul_pd(bc_mat1_1, vecB_mat2));
                    auto bc_mat1_2 = _mm256_set1_pd(a[i+1][k]);
                    sumA_2 = _mm256_add_pd(sumA_2, _mm256_mul_pd(bc_mat1_2, vecA_mat2));
                    sumB_2 = _mm256_add_pd(sumB_2, _mm256_mul_pd(bc_mat1_2, vecB_mat2));
                    auto bc_mat1_3 = _mm256_set1_pd(a[i+2][k]);
                    sumA_3 = _mm256_add_pd(sumA_3, _mm256_mul_pd(bc_mat1_3, vecA_mat2));
                    sumB_3 = _mm256_add_pd(sumB_3, _mm256_mul_pd(bc_mat1_3, vecB_mat2));
                    auto bc_mat1_4 = _mm256_set1_pd(a[i+3][k]);
                    sumA_4 = _mm256_add_pd(sumA_4, _mm256_mul_pd(bc_mat1_4, vecA_mat2));
                    sumB_4 = _mm256_add_pd(sumB_4, _mm256_mul_pd(bc_mat1_4, vecB_mat2));
                }
                _mm256_storeu_pd(&c[i][j], sumA_1);
                _mm256_storeu_pd(&c[i][j + 4], sumB_1);
                _mm256_storeu_pd(&c[i+1][j], sumA_2);
                _mm256_storeu_pd(&c[i+1][j + 4], sumB_2);
                _mm256_storeu_pd(&c[i+2][j], sumA_3);
                _mm256_storeu_pd(&c[i+2][j + 4], sumB_3);
                _mm256_storeu_pd(&c[i+3][j], sumA_4);
                _mm256_storeu_pd(&c[i+3][j + 4], sumB_4);
            }
        }
    }
    _m256d spreadResult = _mm256_setzero_pd();
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 256; j+=8)
            sumA_1 = _mm256_load_pd(&c[i][j]);
            sumB_1 = _mm256_load_pd(&c[i][j + 4]);
            spreadResult = _mm256_add_pd(spreadResult, _mm256_mul_pd(sumA_1, sumA_1));
            spreadResult = _mm256_add_pd(spreadResult, _mm256_mul_pd(sumB_1, sumB_1));
            //answer += c[i][j]*c[i][j];
    __m128d vlow  = _mm256_castpd256_pd128(spreadResult);
    __m128d vhigh = _mm256_extractf128_pd(spreadResult, 1); // high 128
    vlow  = _mm_add_pd(vlow, vhigh);     // reduce down to 128
    __m128d high64 = _mm_unpackhi_pd(vlow, vlow);
    return  _mm_cvtsd_f64(_mm_add_sd(vlow, high64)); //return single
    //return answer;
}
