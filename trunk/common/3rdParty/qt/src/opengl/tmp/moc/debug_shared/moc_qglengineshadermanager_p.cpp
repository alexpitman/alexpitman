/****************************************************************************
** Meta object code from reading C++ file 'qglengineshadermanager_p.h'
**
** Created: Wed Nov 3 12:19:04 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gl2paintengineex/qglengineshadermanager_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qglengineshadermanager_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGLEngineSharedShaders[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   19, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

 // enums: name, flags, count, data
      50, 0x0,   56,   23,

 // enum data: key, value
      62, uint(QGLEngineSharedShaders::MainVertexShader),
      79, uint(QGLEngineSharedShaders::MainWithTexCoordsVertexShader),
     109, uint(QGLEngineSharedShaders::MainWithTexCoordsAndOpacityVertexShader),
     149, uint(QGLEngineSharedShaders::UntransformedPositionVertexShader),
     183, uint(QGLEngineSharedShaders::PositionOnlyVertexShader),
     208, uint(QGLEngineSharedShaders::ComplexGeometryPositionOnlyVertexShader),
     248, uint(QGLEngineSharedShaders::PositionWithPatternBrushVertexShader),
     285, uint(QGLEngineSharedShaders::PositionWithLinearGradientBrushVertexShader),
     329, uint(QGLEngineSharedShaders::PositionWithConicalGradientBrushVertexShader),
     374, uint(QGLEngineSharedShaders::PositionWithRadialGradientBrushVertexShader),
     418, uint(QGLEngineSharedShaders::PositionWithTextureBrushVertexShader),
     455, uint(QGLEngineSharedShaders::AffinePositionWithPatternBrushVertexShader),
     498, uint(QGLEngineSharedShaders::AffinePositionWithLinearGradientBrushVertexShader),
     548, uint(QGLEngineSharedShaders::AffinePositionWithConicalGradientBrushVertexShader),
     599, uint(QGLEngineSharedShaders::AffinePositionWithRadialGradientBrushVertexShader),
     649, uint(QGLEngineSharedShaders::AffinePositionWithTextureBrushVertexShader),
     692, uint(QGLEngineSharedShaders::MainFragmentShader_CMO),
     715, uint(QGLEngineSharedShaders::MainFragmentShader_CM),
     737, uint(QGLEngineSharedShaders::MainFragmentShader_MO),
     759, uint(QGLEngineSharedShaders::MainFragmentShader_M),
     780, uint(QGLEngineSharedShaders::MainFragmentShader_CO),
     802, uint(QGLEngineSharedShaders::MainFragmentShader_C),
     823, uint(QGLEngineSharedShaders::MainFragmentShader_O),
     844, uint(QGLEngineSharedShaders::MainFragmentShader),
     863, uint(QGLEngineSharedShaders::MainFragmentShader_ImageArrays),
     894, uint(QGLEngineSharedShaders::ImageSrcFragmentShader),
     917, uint(QGLEngineSharedShaders::ImageSrcWithPatternFragmentShader),
     951, uint(QGLEngineSharedShaders::NonPremultipliedImageSrcFragmentShader),
     990, uint(QGLEngineSharedShaders::CustomImageSrcFragmentShader),
    1019, uint(QGLEngineSharedShaders::SolidBrushSrcFragmentShader),
    1047, uint(QGLEngineSharedShaders::TextureBrushSrcFragmentShader),
    1077, uint(QGLEngineSharedShaders::TextureBrushSrcWithPatternFragmentShader),
    1118, uint(QGLEngineSharedShaders::PatternBrushSrcFragmentShader),
    1148, uint(QGLEngineSharedShaders::LinearGradientBrushSrcFragmentShader),
    1185, uint(QGLEngineSharedShaders::RadialGradientBrushSrcFragmentShader),
    1222, uint(QGLEngineSharedShaders::ConicalGradientBrushSrcFragmentShader),
    1260, uint(QGLEngineSharedShaders::ShockingPinkSrcFragmentShader),
    1290, uint(QGLEngineSharedShaders::NoMaskFragmentShader),
    1311, uint(QGLEngineSharedShaders::MaskFragmentShader),
    1330, uint(QGLEngineSharedShaders::RgbMaskFragmentShaderPass1),
    1357, uint(QGLEngineSharedShaders::RgbMaskFragmentShaderPass2),
    1384, uint(QGLEngineSharedShaders::RgbMaskWithGammaFragmentShader),
    1415, uint(QGLEngineSharedShaders::NoCompositionModeFragmentShader),
    1447, uint(QGLEngineSharedShaders::MultiplyCompositionModeFragmentShader),
    1485, uint(QGLEngineSharedShaders::ScreenCompositionModeFragmentShader),
    1521, uint(QGLEngineSharedShaders::OverlayCompositionModeFragmentShader),
    1558, uint(QGLEngineSharedShaders::DarkenCompositionModeFragmentShader),
    1594, uint(QGLEngineSharedShaders::LightenCompositionModeFragmentShader),
    1631, uint(QGLEngineSharedShaders::ColorDodgeCompositionModeFragmentShader),
    1671, uint(QGLEngineSharedShaders::ColorBurnCompositionModeFragmentShader),
    1710, uint(QGLEngineSharedShaders::HardLightCompositionModeFragmentShader),
    1749, uint(QGLEngineSharedShaders::SoftLightCompositionModeFragmentShader),
    1788, uint(QGLEngineSharedShaders::DifferenceCompositionModeFragmentShader),
    1828, uint(QGLEngineSharedShaders::ExclusionCompositionModeFragmentShader),
    1867, uint(QGLEngineSharedShaders::TotalSnippetCount),
    1885, uint(QGLEngineSharedShaders::InvalidSnippetName),

       0        // eod
};

static const char qt_meta_stringdata_QGLEngineSharedShaders[] = {
    "QGLEngineSharedShaders\0\0"
    "shaderProgNeedsChanging()\0SnippetName\0"
    "MainVertexShader\0MainWithTexCoordsVertexShader\0"
    "MainWithTexCoordsAndOpacityVertexShader\0"
    "UntransformedPositionVertexShader\0"
    "PositionOnlyVertexShader\0"
    "ComplexGeometryPositionOnlyVertexShader\0"
    "PositionWithPatternBrushVertexShader\0"
    "PositionWithLinearGradientBrushVertexShader\0"
    "PositionWithConicalGradientBrushVertexShader\0"
    "PositionWithRadialGradientBrushVertexShader\0"
    "PositionWithTextureBrushVertexShader\0"
    "AffinePositionWithPatternBrushVertexShader\0"
    "AffinePositionWithLinearGradientBrushVertexShader\0"
    "AffinePositionWithConicalGradientBrushVertexShader\0"
    "AffinePositionWithRadialGradientBrushVertexShader\0"
    "AffinePositionWithTextureBrushVertexShader\0"
    "MainFragmentShader_CMO\0MainFragmentShader_CM\0"
    "MainFragmentShader_MO\0MainFragmentShader_M\0"
    "MainFragmentShader_CO\0MainFragmentShader_C\0"
    "MainFragmentShader_O\0MainFragmentShader\0"
    "MainFragmentShader_ImageArrays\0"
    "ImageSrcFragmentShader\0"
    "ImageSrcWithPatternFragmentShader\0"
    "NonPremultipliedImageSrcFragmentShader\0"
    "CustomImageSrcFragmentShader\0"
    "SolidBrushSrcFragmentShader\0"
    "TextureBrushSrcFragmentShader\0"
    "TextureBrushSrcWithPatternFragmentShader\0"
    "PatternBrushSrcFragmentShader\0"
    "LinearGradientBrushSrcFragmentShader\0"
    "RadialGradientBrushSrcFragmentShader\0"
    "ConicalGradientBrushSrcFragmentShader\0"
    "ShockingPinkSrcFragmentShader\0"
    "NoMaskFragmentShader\0MaskFragmentShader\0"
    "RgbMaskFragmentShaderPass1\0"
    "RgbMaskFragmentShaderPass2\0"
    "RgbMaskWithGammaFragmentShader\0"
    "NoCompositionModeFragmentShader\0"
    "MultiplyCompositionModeFragmentShader\0"
    "ScreenCompositionModeFragmentShader\0"
    "OverlayCompositionModeFragmentShader\0"
    "DarkenCompositionModeFragmentShader\0"
    "LightenCompositionModeFragmentShader\0"
    "ColorDodgeCompositionModeFragmentShader\0"
    "ColorBurnCompositionModeFragmentShader\0"
    "HardLightCompositionModeFragmentShader\0"
    "SoftLightCompositionModeFragmentShader\0"
    "DifferenceCompositionModeFragmentShader\0"
    "ExclusionCompositionModeFragmentShader\0"
    "TotalSnippetCount\0InvalidSnippetName\0"
};

const QMetaObject QGLEngineSharedShaders::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGLEngineSharedShaders,
      qt_meta_data_QGLEngineSharedShaders, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGLEngineSharedShaders::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGLEngineSharedShaders::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGLEngineSharedShaders::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGLEngineSharedShaders))
        return static_cast<void*>(const_cast< QGLEngineSharedShaders*>(this));
    return QObject::qt_metacast(_clname);
}

int QGLEngineSharedShaders::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: shaderProgNeedsChanging(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QGLEngineSharedShaders::shaderProgNeedsChanging()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QGLEngineShaderManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QGLEngineShaderManager[] = {
    "QGLEngineShaderManager\0\0"
    "shaderProgNeedsChangingSlot()\0"
};

const QMetaObject QGLEngineShaderManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QGLEngineShaderManager,
      qt_meta_data_QGLEngineShaderManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGLEngineShaderManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGLEngineShaderManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGLEngineShaderManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGLEngineShaderManager))
        return static_cast<void*>(const_cast< QGLEngineShaderManager*>(this));
    return QObject::qt_metacast(_clname);
}

int QGLEngineShaderManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: shaderProgNeedsChangingSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
