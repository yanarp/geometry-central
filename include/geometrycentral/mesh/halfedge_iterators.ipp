#pragma once

namespace geometrycentral {
namespace halfedge_mesh {

// ==========================================================
// ================    Vertex Iterators    ==================
// ==========================================================

// === Incoming halfedges, including those on the domain boundary
inline VertexIncomingHalfedgeIterator VertexIncomingHalfedgeSet::begin() {
  return VertexIncomingHalfedgeIterator(firstHe, true);
}
inline VertexIncomingHalfedgeIterator VertexIncomingHalfedgeSet::end() {
  return VertexIncomingHalfedgeIterator(firstHe, false);
}
inline const VertexIncomingHalfedgeIterator& VertexIncomingHalfedgeIterator::operator++() {
  justStarted = false;
  currHe = currHe.next().twin();
  return *this;
}
inline bool VertexIncomingHalfedgeIterator::operator==(const VertexIncomingHalfedgeIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexIncomingHalfedgeIterator::operator!=(const VertexIncomingHalfedgeIterator& other) const {
  return !(*this == other);
}
inline Halfedge VertexIncomingHalfedgeIterator::operator*() const { return currHe; }


// === Outgoing halfedges, including those on the domain boundary
inline VertexOutgoingHalfedgeIterator VertexOutgoingHalfedgeSet::begin() {
  return VertexOutgoingHalfedgeIterator(firstHe, true);
}
inline VertexOutgoingHalfedgeIterator VertexOutgoingHalfedgeSet::end() {
  return VertexOutgoingHalfedgeIterator(firstHe, false);
}
inline const VertexOutgoingHalfedgeIterator& VertexOutgoingHalfedgeIterator::operator++() {
  justStarted = false;
  currHe = currHe.twin().next();
  return *this;
}
inline bool VertexOutgoingHalfedgeIterator::operator==(const VertexOutgoingHalfedgeIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexOutgoingHalfedgeIterator::operator!=(const VertexOutgoingHalfedgeIterator& other) const {
  return !(*this == other);
}
inline Halfedge VertexOutgoingHalfedgeIterator::operator*() const { return currHe; }

// === Adjacent vertices
inline VertexAdjacentVertexIterator VertexAdjacentVertexSet::begin() {
  return VertexAdjacentVertexIterator(firstHe, true);
}
inline VertexAdjacentVertexIterator VertexAdjacentVertexSet::end() {
  return VertexAdjacentVertexIterator(firstHe, false);
}
inline const VertexAdjacentVertexIterator& VertexAdjacentVertexIterator::operator++() {
  justStarted = false;
  currHe = currHe.next().twin();
  return *this;
}
inline bool VertexAdjacentVertexIterator::operator==(const VertexAdjacentVertexIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexAdjacentVertexIterator::operator!=(const VertexAdjacentVertexIterator& other) const {
  return !(*this == other);
}
inline Vertex VertexAdjacentVertexIterator::operator*() const { return currHe.vertex(); }

// === Adjacent faces
inline VertexAdjacentFaceIterator VertexAdjacentFaceSet::begin() { return VertexAdjacentFaceIterator(firstHe, true); }
inline VertexAdjacentFaceIterator VertexAdjacentFaceSet::end() { return VertexAdjacentFaceIterator(firstHe, false); }
inline const VertexAdjacentFaceIterator& VertexAdjacentFaceIterator::operator++() {
  justStarted = false;
  do {
    currHe = currHe.twin().next();
  } while (!currHe.isInterior());
  return *this;
}
inline bool VertexAdjacentFaceIterator::operator==(const VertexAdjacentFaceIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexAdjacentFaceIterator::operator!=(const VertexAdjacentFaceIterator& other) const {
  return !(*this == other);
}
inline Face VertexAdjacentFaceIterator::operator*() const { return currHe.face(); }

// === Adjacent edges
inline VertexAdjacentEdgeIterator VertexAdjacentEdgeSet::begin() { return VertexAdjacentEdgeIterator(firstHe, true); }
inline VertexAdjacentEdgeIterator VertexAdjacentEdgeSet::end() { return VertexAdjacentEdgeIterator(firstHe, false); }
inline const VertexAdjacentEdgeIterator& VertexAdjacentEdgeIterator::operator++() {
  justStarted = false;
  currHe = currHe.twin().next();
  return *this;
}
inline bool VertexAdjacentEdgeIterator::operator==(const VertexAdjacentEdgeIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexAdjacentEdgeIterator::operator!=(const VertexAdjacentEdgeIterator& other) const {
  return !(*this == other);
}
inline Edge VertexAdjacentEdgeIterator::operator*() const { return currHe.edge(); }

// === Adjacent corners
inline VertexAdjacentCornerIterator VertexAdjacentCornerSet::begin() {
  return VertexAdjacentCornerIterator(firstHe, true);
}
inline VertexAdjacentCornerIterator VertexAdjacentCornerSet::end() {
  return VertexAdjacentCornerIterator(firstHe, false);
}
inline const VertexAdjacentCornerIterator& VertexAdjacentCornerIterator::operator++() {
  justStarted = false;
  currHe = currHe.twin().next();
  if (!currHe.isInterior()) currHe = currHe.twin().next(); // currHe must always be real
  return *this;
}
inline bool VertexAdjacentCornerIterator::operator==(const VertexAdjacentCornerIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool VertexAdjacentCornerIterator::operator!=(const VertexAdjacentCornerIterator& other) const {
  return !(*this == other);
}
inline Corner VertexAdjacentCornerIterator::operator*() const { return currHe.next().corner(); }

// ==========================================================
// ================     Face Iterators     ==================
// ==========================================================

// === Adjacent halfedges
inline FaceAdjacentHalfedgeIterator FaceAdjacentHalfedgeSet::begin() {
  return FaceAdjacentHalfedgeIterator(firstHe, true);
}
inline FaceAdjacentHalfedgeIterator FaceAdjacentHalfedgeSet::end() {
  return FaceAdjacentHalfedgeIterator(firstHe, false);
}
inline const FaceAdjacentHalfedgeIterator& FaceAdjacentHalfedgeIterator::operator++() {
  justStarted = false;
  currHe = currHe.next();
  return *this;
}
inline bool FaceAdjacentHalfedgeIterator::operator==(const FaceAdjacentHalfedgeIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool FaceAdjacentHalfedgeIterator::operator!=(const FaceAdjacentHalfedgeIterator& other) const {
  return !(*this == other);
}
inline Halfedge FaceAdjacentHalfedgeIterator::operator*() const { return currHe; }

// === Adjacent vertices
inline FaceAdjacentVertexIterator FaceAdjacentVertexSet::begin() { return FaceAdjacentVertexIterator(firstHe, true); }
inline FaceAdjacentVertexIterator FaceAdjacentVertexSet::end() { return FaceAdjacentVertexIterator(firstHe, false); }
inline const FaceAdjacentVertexIterator& FaceAdjacentVertexIterator::operator++() {
  justStarted = false;
  currHe = currHe.next();
  return *this;
}
inline bool FaceAdjacentVertexIterator::operator==(const FaceAdjacentVertexIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool FaceAdjacentVertexIterator::operator!=(const FaceAdjacentVertexIterator& other) const {
  return !(*this == other);
}
inline Vertex FaceAdjacentVertexIterator::operator*() const { return currHe.vertex(); }

// === Adjacent edges
inline FaceAdjacentEdgeIterator FaceAdjacentEdgeSet::begin() { return FaceAdjacentEdgeIterator(firstHe, true); }
inline FaceAdjacentEdgeIterator FaceAdjacentEdgeSet::end() { return FaceAdjacentEdgeIterator(firstHe, false); }
inline const FaceAdjacentEdgeIterator& FaceAdjacentEdgeIterator::operator++() {
  justStarted = false;
  currHe = currHe.next();
  return *this;
}
inline bool FaceAdjacentEdgeIterator::operator==(const FaceAdjacentEdgeIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool FaceAdjacentEdgeIterator::operator!=(const FaceAdjacentEdgeIterator& other) const {
  return !(*this == other);
}
inline Edge FaceAdjacentEdgeIterator::operator*() const { return currHe.edge(); }

// === Adjacent faces
inline FaceAdjacentFaceIterator FaceAdjacentFaceSet::begin() { return FaceAdjacentFaceIterator(firstHe, true); }
inline FaceAdjacentFaceIterator FaceAdjacentFaceSet::end() { return FaceAdjacentFaceIterator(firstHe, false); }
inline const FaceAdjacentFaceIterator& FaceAdjacentFaceIterator::operator++() {
  justStarted = false;
  do {
    currHe = currHe.next();
  } while (!currHe.twin().isInterior());
  return *this;
}
inline bool FaceAdjacentFaceIterator::operator==(const FaceAdjacentFaceIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool FaceAdjacentFaceIterator::operator!=(const FaceAdjacentFaceIterator& other) const {
  return !(*this == other);
}
inline Face FaceAdjacentFaceIterator::operator*() const { return currHe.twin().face(); }

// === Adjacent corners
inline FaceAdjacentCornerIterator FaceAdjacentCornerSet::begin() { return FaceAdjacentCornerIterator(firstHe, true); }
inline FaceAdjacentCornerIterator FaceAdjacentCornerSet::end() { return FaceAdjacentCornerIterator(firstHe, false); }
inline const FaceAdjacentCornerIterator& FaceAdjacentCornerIterator::operator++() {
  justStarted = false;
  currHe = currHe.next();
  return *this;
}
inline bool FaceAdjacentCornerIterator::operator==(const FaceAdjacentCornerIterator& other) const {
  return currHe == other.currHe && justStarted == other.justStarted;
}
inline bool FaceAdjacentCornerIterator::operator!=(const FaceAdjacentCornerIterator& other) const {
  return !(*this == other);
}
inline Corner FaceAdjacentCornerIterator::operator*() const { return currHe.next().corner(); }

} // namespace halfedge_mesh
} // namespace geometrycentral
