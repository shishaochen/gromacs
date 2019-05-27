/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 2018,2019, by the GROMACS development team, led by
 * Mark Abraham, David van der Spoel, Berk Hess, and Erik Lindahl,
 * and including many others, as listed in the AUTHORS file in the
 * top-level source directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */
/*! \internal \file
 * \brief Stub for function that applies SETTLE on GPU.
 *
 * \author Artem Zhmurov <zhmurov@gmail.com>
 * \ingroup module_mdlib
 */
#include "gmxpre.h"

#include "settle_impl.h"

#include "config.h"

#include <gtest/gtest.h>

#include "gromacs/math/vectypes.h"
#include "gromacs/pbcutil/pbc.h"
#include "gromacs/topology/idef.h"
#include "gromacs/topology/topology.h"

#include "testutils/testasserts.h"

namespace gmx
{
namespace test
{

#if GMX_GPU != GMX_GPU_CUDA

void applySettleCuda(int              gmx_unused  numAtoms,
                     const rvec       gmx_unused *h_x,
                     rvec             gmx_unused *h_xp,
                     bool             gmx_unused  updateVelocities,
                     rvec             gmx_unused *h_v,
                     real             gmx_unused  invdt,
                     bool             gmx_unused  computeVirial,
                     tensor           gmx_unused  virialScaled,
                     const t_pbc      gmx_unused *pbc,
                     const gmx_mtop_t gmx_unused &mtop,
                     const t_idef     gmx_unused &idef,
                     const t_mdatoms  gmx_unused &mdatoms)
{
    EXPECT_TRUE(false) << "Dummy SETTLE CUDA function was called instead of the real one in the SETTLE test.";
}

#endif
} // namespace test
} // namespace gmx
