# Generalized Plane Strain Action System

!syntax description /Modules/TensorMechanics/GeneralizedPlaneStrain/GeneralizedPlaneStrainAction

## Description

This action sets up a generalized plane strain model. A detailed description of generalized plane strain model can be found in the [formulation](tensor_mechanics/generalized_plane_strain.md) page.

!alert warning title=For 2D and 1D Simulations
GeneralizedPlaneStrain only works for 1D axisymmetric or 2D generalized plane strain cases where the number of displacement variables is only one or two displacements.

## Constructed MooseObjects

The `GeneralizedPlaneStrain` Action is used to construct the kernels, user objects, and scalar out-of-plane variables in a consistent manner as required for a generalized plane strain simulation.

!table id=generalizedPS_action_table caption=Correspondence Among Action Functionality and MooseObjects for the `GeneralizedPlaneStrain` Action
| Functionality     | Replaced Classes   | Associated Parameters   |
|-------------------|--------------------|-------------------------|
| Scalar out-of-plan strain coupling with in-plane field variables | [Generalized Plane Strain Off-diagonal Kernel](/GeneralizedPlaneStrainOffDiag.md) | `scalar_out_of_plane_strain`: a list of the scalar variables for the out-of-plane strain direction |
| | | `displacements` : a string of the displacement field (in-plane) variables |
| | | `temperature`: a string of the temperature field variable |
| Out-of-plane scalar variable equilibrium condition | [Generalized Plane Strain ScalarKernel](/GeneralizedPlaneStrain.md) | `scalar_out_of_plane_strain`: a list of the scalar variables for the out-of-plane strain direction |
| Residual and diagonal Jacobian calculation for scalar out-of-plane strain variables | [Generalized Plane Strain UserObject](/GeneralizedPlaneStrainUserObject.md) | `scalar_out_of_plane_strain`: a list of the scalar variables for the out-of-plane strain direction |

## Example Input Syntax

### Subblocks

The subblocks of the GeneralizedPlaneStrain action are what triggers MOOSE objects to be built.
If a generalized plane strain model is applied for the whole simulation domain, a single subblock should be used

!listing modules/tensor_mechanics/test/tests/generalized_plane_strain/generalized_plane_strain_finite.i block=Modules/TensorMechanics/GeneralizedPlaneStrain

if different mesh subdomain has different generalized plane strain model, multiple subblocks with subdomain restrictions can be used.

!listing modules/tensor_mechanics/test/tests/generalized_plane_strain/generalized_plane_strain_squares.i block=Modules/TensorMechanics/GeneralizedPlaneStrain

Parameters supplied at the `[Modules/TensorMechanics/GeneralizedPlaneStrain]` level act as
defaults for the Master action subblocks.

!syntax parameters /Modules/TensorMechanics/GeneralizedPlaneStrain/GeneralizedPlaneStrainAction


## Associated Actions

!syntax list /Modules/TensorMechanics/GeneralizedPlaneStrain objects=True actions=False subsystems=False

!syntax list /Modules/TensorMechanics/GeneralizedPlaneStrain objects=False actions=False subsystems=True

!syntax list /Modules/TensorMechanics/GeneralizedPlaneStrain objects=False actions=True subsystems=False
