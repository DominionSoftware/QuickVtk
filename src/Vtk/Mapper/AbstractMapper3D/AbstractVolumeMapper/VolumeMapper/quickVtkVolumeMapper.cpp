#include "quickVtkVolumeMapper.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::AbstractClass<VolumeMapper> VolumeMapper::Register;

        VolumeMapper::VolumeMapper(vtkSmartPointer<vtkVolumeMapper> vtkObject) : AbstractVolumeMapper(vtkObject) {
            this->m_vtkObject = vtkVolumeMapper::SafeDownCast(vtkObject);
        }

        auto VolumeMapper::setBlendMode(BlendMode blendMode) -> void {
            this->m_vtkObject->SetBlendMode(blendMode);
            emit this->blendModeChanged();
            this->update();
        }

        auto VolumeMapper::getBlendMode() -> BlendMode {
            return (BlendMode) this->m_vtkObject->GetBlendMode();
        }
    }
}