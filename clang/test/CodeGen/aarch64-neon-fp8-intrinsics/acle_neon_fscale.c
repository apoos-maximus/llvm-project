// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: aarch64-registered-target
#include <arm_neon.h>

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon -target-feature +fp8 -O3 -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon -target-feature +fp8 -S -O3 -o /dev/null %s

// CHECK-LABEL: define dso_local <4 x half> @test_vscale_f16(
// CHECK-SAME: <4 x half> noundef [[VN:%.*]], <4 x i16> noundef [[VM:%.*]]) local_unnamed_addr #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FSCALE2_I:%.*]] = tail call <4 x half> @llvm.aarch64.neon.fp8.fscale.v4f16(<4 x half> [[VN]], <4 x i16> [[VM]])
// CHECK-NEXT:    ret <4 x half> [[FSCALE2_I]]
//
float16x4_t test_vscale_f16(float16x4_t vn, int16x4_t vm) {
  return vscale_f16(vn, vm);
}

// CHECK-LABEL: define dso_local <8 x half> @test_vscaleq_f16(
// CHECK-SAME: <8 x half> noundef [[VN:%.*]], <8 x i16> noundef [[VM:%.*]]) local_unnamed_addr #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FSCALE2_I:%.*]] = tail call <8 x half> @llvm.aarch64.neon.fp8.fscale.v8f16(<8 x half> [[VN]], <8 x i16> [[VM]])
// CHECK-NEXT:    ret <8 x half> [[FSCALE2_I]]
//
float16x8_t test_vscaleq_f16(float16x8_t vn, int16x8_t vm) {
  return vscaleq_f16(vn, vm);

}

// CHECK-LABEL: define dso_local <2 x float> @test_vscale_f32(
// CHECK-SAME: <2 x float> noundef [[VN:%.*]], <2 x i32> noundef [[VM:%.*]]) local_unnamed_addr #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FSCALE2_I:%.*]] = tail call <2 x float> @llvm.aarch64.neon.fp8.fscale.v2f32(<2 x float> [[VN]], <2 x i32> [[VM]])
// CHECK-NEXT:    ret <2 x float> [[FSCALE2_I]]
//
float32x2_t test_vscale_f32(float32x2_t vn, int32x2_t vm) {
  return vscale_f32(vn, vm);

}

// CHECK-LABEL: define dso_local <4 x float> @test_vscaleq_f32(
// CHECK-SAME: <4 x float> noundef [[VN:%.*]], <4 x i32> noundef [[VM:%.*]]) local_unnamed_addr #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FSCALE2_I:%.*]] = tail call <4 x float> @llvm.aarch64.neon.fp8.fscale.v4f32(<4 x float> [[VN]], <4 x i32> [[VM]])
// CHECK-NEXT:    ret <4 x float> [[FSCALE2_I]]
//
float32x4_t test_vscaleq_f32(float32x4_t vn, int32x4_t vm) {
  return vscaleq_f32(vn, vm);

}

// CHECK-LABEL: define dso_local <2 x double> @test_vscale_f64(
// CHECK-SAME: <2 x double> noundef [[VN:%.*]], <2 x i64> noundef [[VM:%.*]]) local_unnamed_addr #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FSCALE2_I:%.*]] = tail call <2 x double> @llvm.aarch64.neon.fp8.fscale.v2f64(<2 x double> [[VN]], <2 x i64> [[VM]])
// CHECK-NEXT:    ret <2 x double> [[FSCALE2_I]]
//
float64x2_t test_vscale_f64(float64x2_t vn, int64x2_t vm) {
  return vscaleq_f64(vn, vm);
}
