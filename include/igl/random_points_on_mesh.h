// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_RANDOM_POINTS_ON_MESH_H
#define IGL_RANDOM_POINTS_ON_MESH_H

#include "igl_inline.h"
#include <Eigen/Core>
#include <Eigen/Sparse>

namespace igl
{
  // RANDOM_POINTS_ON_MESH Randomly sample a mesh (V,F) n times.
  //
  //
  // When urbg is not specified, random_points_on_mesh will use default random bit generator
  // std::minstd_rand initialized with default seed
  //
  // Inputs:
  //   urbg An instance of UnformRandomBitGenerator.
  //   n  number of samples
  //   V  #V by dim list of mesh vertex positions
  //   F  #F by 3 list of mesh triangle indices
  // Outputs:
  //   B  n by 3 list of barycentric coordinates, ith row are coordinates of
  //     ith sampled point in face FI(i)
  //   FI  n list of indices into F 
  //
  template <typename DerivedV, typename DerivedF, typename URBG, typename DerivedB, typename DerivedFI>
  IGL_INLINE void random_points_on_mesh(
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::PlainObjectBase<DerivedB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI);
  template <typename URBG, typename DerivedV, typename DerivedF, typename DerivedB, typename DerivedFI>
  IGL_INLINE void random_points_on_mesh(
    URBG && urbg,
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::PlainObjectBase<DerivedB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI);  
  // Outputs:
  //   X  n by dim list of sample positions.
  template <
    typename DerivedV, 
    typename DerivedF, 
    typename DerivedB, 
    typename DerivedFI,
    typename DerivedX>
  IGL_INLINE void random_points_on_mesh(
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::PlainObjectBase<DerivedB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI,
    Eigen::PlainObjectBase<DerivedX> & X);
  template <
    typename URBG,
    typename DerivedV, 
    typename DerivedF, 
    typename DerivedB, 
    typename DerivedFI,
    typename DerivedX>
  IGL_INLINE void random_points_on_mesh(
    URBG && urbg,
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::PlainObjectBase<DerivedB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI,
    Eigen::PlainObjectBase<DerivedX> & X);  
  // Outputs:
  //   B n by #V sparse matrix so that  B*V produces a list of sample points
  template <typename DerivedV, typename DerivedF, typename ScalarB, typename DerivedFI>
  IGL_INLINE void random_points_on_mesh(
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::SparseMatrix<ScalarB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI);
  template <typename URBG, typename DerivedV, typename DerivedF,  typename ScalarB, typename DerivedFI>
  IGL_INLINE void random_points_on_mesh(
    URBG && urbg,
    const int n,
    const Eigen::MatrixBase<DerivedV > & V,
    const Eigen::MatrixBase<DerivedF > & F,
    Eigen::SparseMatrix<ScalarB > & B,
    Eigen::PlainObjectBase<DerivedFI > & FI);  
}

#ifndef IGL_STATIC_LIBRARY
#  include "random_points_on_mesh.cpp"
#endif

#endif
