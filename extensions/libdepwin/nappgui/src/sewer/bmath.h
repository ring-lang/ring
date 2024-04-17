/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmath.h
 * https://nappgui.com/en/sewer/bmath.html
 *
 */

/* Math funcions */

#include "sewer.hxx"

__EXTERN_C

_sewer_api real32_t bmath_cosf(const real32_t angle);

_sewer_api real64_t bmath_cosd(const real64_t angle);

_sewer_api real32_t bmath_sinf(const real32_t angle);

_sewer_api real64_t bmath_sind(const real64_t angle);

_sewer_api real32_t bmath_tanf(const real32_t angle);

_sewer_api real64_t bmath_tand(const real64_t angle);

_sewer_api real32_t bmath_acosf(const real32_t cos);

_sewer_api real64_t bmath_acosd(const real64_t cos);

_sewer_api real32_t bmath_asinf(const real32_t sin);

_sewer_api real64_t bmath_asind(const real64_t sin);

_sewer_api real32_t bmath_atan2f(const real32_t y, const real32_t x);

_sewer_api real64_t bmath_atan2d(const real64_t y, const real64_t x);

_sewer_api real32_t bmath_norm_anglef(const real32_t a);

_sewer_api real64_t bmath_norm_angled(const real64_t a);

_sewer_api real32_t bmath_sqrtf(const real32_t value);

_sewer_api real64_t bmath_sqrtd(const real64_t value);

_sewer_api real32_t bmath_isqrtf(const real32_t value);

_sewer_api real64_t bmath_isqrtd(const real64_t value);

_sewer_api real32_t bmath_logf(const real32_t value);

_sewer_api real64_t bmath_logd(const real64_t value);

_sewer_api real32_t bmath_log10f(const real32_t value);

_sewer_api real64_t bmath_log10d(const real64_t value);

_sewer_api real32_t bmath_expf(const real32_t value);

_sewer_api real64_t bmath_expd(const real64_t value);

_sewer_api real32_t bmath_powf(const real32_t base, const real32_t exponent);

_sewer_api real64_t bmath_powd(const real64_t base, const real64_t exponent);

_sewer_api real32_t bmath_absf(const real32_t value);

_sewer_api real64_t bmath_absd(const real64_t value);

_sewer_api real32_t bmath_maxf(const real32_t value1, const real32_t value2);

_sewer_api real64_t bmath_maxd(const real64_t value1, const real64_t value2);

_sewer_api real32_t bmath_minf(const real32_t value1, const real32_t value2);

_sewer_api real64_t bmath_mind(const real64_t value1, const real64_t value2);

_sewer_api real32_t bmath_clampf(const real32_t value, const real32_t min, const real32_t max);

_sewer_api real64_t bmath_clampd(const real64_t value, const real64_t min, const real64_t max);

_sewer_api real32_t bmath_modf(const real32_t num, const real32_t den);

_sewer_api real64_t bmath_modd(const real64_t num, const real64_t den);

_sewer_api real32_t bmath_modff(const real32_t value, real32_t *intpart);

_sewer_api real64_t bmath_modfd(const real64_t value, real64_t *intpart);

_sewer_api uint32_t bmath_precf(const real32_t value);

_sewer_api uint32_t bmath_precd(const real64_t value);

_sewer_api real32_t bmath_roundf(const real32_t value);

_sewer_api real64_t bmath_roundd(const real64_t value);

_sewer_api real32_t bmath_round_stepf(const real32_t value, const real32_t step);

_sewer_api real64_t bmath_round_stepd(const real64_t value, const real64_t step);

_sewer_api real32_t bmath_floorf(const real32_t value);

_sewer_api real64_t bmath_floord(const real64_t value);

_sewer_api real32_t bmath_ceilf(const real32_t value);

_sewer_api real64_t bmath_ceild(const real64_t value);

_sewer_api void bmath_rand_seed(const uint32_t seed);

_sewer_api real32_t bmath_randf(const real32_t from, const real32_t to);

_sewer_api real64_t bmath_randd(const real64_t from, const real64_t to);

_sewer_api uint32_t bmath_randi(const uint32_t from, const uint32_t to);

_sewer_api REnv *bmath_rand_env(const uint32_t seed);

_sewer_api void bmath_rand_destroy(REnv **env);

_sewer_api real32_t bmath_rand_mtf(REnv *env, const real32_t from, const real32_t to);

_sewer_api real64_t bmath_rand_mtd(REnv *env, const real64_t from, const real64_t to);

_sewer_api uint32_t bmath_rand_mti(REnv *env, const uint32_t from, const uint32_t to);

_sewer_api extern const real32_t kBMATH_Ef;
_sewer_api extern const real64_t kBMATH_Ed;
_sewer_api extern const real32_t kBMATH_LN2f;
_sewer_api extern const real64_t kBMATH_LN2d;
_sewer_api extern const real32_t kBMATH_LN10f;
_sewer_api extern const real64_t kBMATH_LN10d;
_sewer_api extern const real32_t kBMATH_PIf;
_sewer_api extern const real64_t kBMATH_PId;
_sewer_api extern const real32_t kBMATH_SQRT2f;
_sewer_api extern const real64_t kBMATH_SQRT2d;
_sewer_api extern const real32_t kBMATH_SQRT3f;
_sewer_api extern const real64_t kBMATH_SQRT3d;
_sewer_api extern const real32_t kBMATH_DEG2RADf;
_sewer_api extern const real64_t kBMATH_DEG2RADd;
_sewer_api extern const real32_t kBMATH_RAD2DEGf;
_sewer_api extern const real64_t kBMATH_RAD2DEGd;
_sewer_api extern const real32_t kBMATH_INFINITYf;
_sewer_api extern const real64_t kBMATH_INFINITYd;

__END_C
