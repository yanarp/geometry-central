#pragma once

#include "geometrycentral/surface/halfedge_mesh.h"
#include "geometrycentral/surface/intrinsic_geometry_interface.h"

#include <Eigen/SparseCore>

namespace geometrycentral {
namespace surface {


class EdgeLengthGeometry : public IntrinsicGeometryInterface {

public:
  EdgeLengthGeometry(HalfedgeMesh& mesh_);
  EdgeLengthGeometry(HalfedgeMesh& mesh_, EdgeData<double>& inputEdgeLengths);
  virtual ~EdgeLengthGeometry() {}
  
  // Construct a new geometry which is exactly the same as this one, on the same mesh.
  // This is a deep copy, no quantites are shared, etc. Require counts/computed quantities are not copied.
  std::unique_ptr<EdgeLengthGeometry> copy();

  // Construct a new geometry which is exactly the same as this one, on another mesh.
  // This is a deep copy, no quantites are shared, etc. Require counts/computed quantities are not copied.
  // The meshes must be in correspondence (have the same connectivity).
  std::unique_ptr<EdgeLengthGeometry> reinterpretTo(HalfedgeMesh& targetMesh);

  EdgeData<double> inputEdgeLengths;

  // == Immediates
  double faceArea(Face f) const;
  double cornerAngle(Corner c) const;
  double halfedgeCotanWeight(Halfedge he) const;
  double edgeCotanWeight(Edge e) const;


protected:
  // Override the compute edge lengths method from intrinsic geometry.
  virtual void computeEdgeLengths() override;


private:
};

} // namespace surface
} // namespace geometrycentral

#include "geometrycentral/surface/edge_length_geometry.ipp"
