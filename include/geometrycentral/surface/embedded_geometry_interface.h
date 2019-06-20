#pragma once

#include "geometrycentral/surface/extrinsic_geometry_interface.h"
#include "geometrycentral/surface/halfedge_mesh.h"
#include "geometrycentral/utilities/vector3.h"

#include <Eigen/SparseCore>

namespace geometrycentral {
namespace surface {


class EmbeddedGeometryInterface : public ExtrinsicGeometryInterface {

protected:
  // Constructor is protected, because this class is an interface which is not meant to be instantiated directly.
  // Instantiate it via some realization which encapsulates input data, like VertexPositionGeometry.
  EmbeddedGeometryInterface(HalfedgeMesh& mesh_);
  virtual ~EmbeddedGeometryInterface() {}

public:
  // == Quantities

  // Vertex positions
  VertexData<Vector3> vertexPositions;
  void requireVertexPositions();
  void unrequireVertexPositions();
  
  // Face normal
  FaceData<Vector3> faceNormals;
  void requireFaceNormals();
  void unrequireFaceNormals();
  
  // Vertex normal
  VertexData<Vector3> vertexNormals;
  void requireVertexNormals();
  void unrequireVertexNormals();
  
  // Face tangent basis
  FaceData<std::array<Vector3,2>> faceTangentBasis;
  void requireFaceTangentBasis();
  void unrequireFaceTangentBasis();
  
  // Vertex tangent basis
  VertexData<std::array<Vector3,2>> vertexTangentBasis;
  void requireVertexTangentBasis();
  void unrequireVertexTangentBasis();
  
protected:

  // == Implmentations of quantities from base classes
  virtual void computeEdgeLengths() override;
  virtual void computeEdgeDihedralAngles() override;
  
  // == Quantities

  DependentQuantityD<VertexData<Vector3>> vertexPositionsQ;
  virtual void computeVertexPositions() = 0;

  DependentQuantityD<FaceData<Vector3>> faceNormalsQ;
  virtual void computeFaceNormals();
  
  DependentQuantityD<VertexData<Vector3>> vertexNormalsQ;
  virtual void computeVertexNormals();

  DependentQuantityD<FaceData<std::array<Vector3,2>>> faceTangentBasisQ;
  virtual void computeFaceTangentBasis();
  
  DependentQuantityD<VertexData<std::array<Vector3,2>>> vertexTangentBasisQ;
  virtual void computeVertexTangentBasis();

  // == Overrides to compute things better using vertex positions
  virtual void computeFaceAreas() override;
  virtual void computeCornerAngles() override;
  virtual void computeHalfedgeCotanWeights() override;
  virtual void computeEdgeCotanWeights() override;
};


} // namespace surface
} // namespace geometrycentral
