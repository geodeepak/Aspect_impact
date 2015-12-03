/*
  Copyright (C) 2014 by the authors of the ASPECT code.

  This file is part of ASPECT.

  ASPECT is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  ASPECT is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ASPECT; see the file doc/COPYING.  If not see
  <http://www.gnu.org/licenses/>.
*/


#ifndef __aspect__gravity_model_layer_density_h
#define __aspect__gravity_model_layer_density_h

#include <aspect/simulator.h>
#include <aspect/gravity_model/interface.h>

namespace aspect
{
  namespace GravityModel
  {
    using namespace dealii;

    /**
     * A class that describes gravity as a radial vector of constant
     * magnitude. The magnitude's value is read from the input file.
     *
     * @ingroup GravityModels
     */
    template <int dim>
    class LayerDensity : public Interface<dim>
    {
      public:
        /**
         * Return the gravity vector as a function of position.
         */
        virtual Tensor<1,dim> gravity_vector (const Point<dim> &position) const;

        /**
         * Declare the parameters this class takes through input files.
         */
        static
        void
        declare_parameters (ParameterHandler &prm);

        /**
         * Read the parameters this class declares from the parameter file.
         */
        virtual
        void
        parse_parameters (ParameterHandler &prm);

      private:
        /**
         * Layer radiuses from inner to outer
         */
        std::vector<double> radiuses;
        /**
         * Layer densities from inner to outer
         */
        std::vector<double> densities;
        /**
         * Number of layers
         */
        double              n_layers;
    };
  }
}

#endif