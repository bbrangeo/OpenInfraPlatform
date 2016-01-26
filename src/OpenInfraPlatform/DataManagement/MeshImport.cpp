#include "OpenInfraPlatform/DataManagement/MeshImport.h"

#include "buw.BlueEngine.h"

OpenInfraPlatform::DataManagement::MeshImport::MeshImport(const std::string& filename, const buw::vector3d& offsetViewArea) :
	buw::Import(filename)
{
	buw::ReferenceCounted<buw::Surface> s = std::make_shared<buw::Surface>();

	buw::ObjReader objReader;
	objReader.load(filename.c_str());
	int chunkCount = objReader.getChunkCount();

	buw::ReferenceCounted<buw::SimpleMesh> sm = buw::ConvertToSimpleMesh(objReader.getChunk(0));
	for (int i = 0; i < sm->GetVertexCount(); i++)
	{
		buw::VertexPosition3Normal3Texture2 v;
		sm->GetVertex(i, v);
		s->addPoint(buw::vector3d(v.position.x(), v.position.y(), v.position.z()));
	}

	for (int i = 0; i < sm->GetIndexCount(); i += 3)
	{
		int i1 = sm->GetIndexDataPointer()[i];
		int i2 = sm->GetIndexDataPointer()[i + 1];
		int i3 = sm->GetIndexDataPointer()[i + 2];

		s->addTriangle(buw::vector3i(i1, i2, i3));
	}

	s->setName("Mesh terrain");

	digitalElevationModel_->addSurface(s);
}