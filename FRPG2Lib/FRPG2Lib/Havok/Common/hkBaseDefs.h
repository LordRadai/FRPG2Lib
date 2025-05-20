#pragma once
#include <Windows.h>
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;

#define HK_ALIGN(DECL, ALIGNMENT) __declspec(align(ALIGNMENT)) DECL
#define HK_ALIGN8(DECL) __declspec(align(8)) DECL
#define HK_ALIGN16(DECL) __declspec(align(16)) DECL
#define HK_ALIGN32(DECL) __declspec(align(32)) DECL
#define HK_ALIGN64(DECL) __declspec(align(64)) DECL
#define HK_ALIGN128(DECL) __declspec(align(128)) DECL

#define HK_CLASSALIGN(DECL, ALIGNMENT) HK_ALIGN(DECL, ALIGNMENT)
#define HK_CLASSALIGN8(DECL) HK_ALIGN8(DECL)
#define HK_CLASSALIGN16(DECL) HK_ALIGN16(DECL)

typedef HK_ALIGN16(Vector4) hkVector4;
typedef HK_ALIGN16(Quaternion) hkQuaternion;

//DO NOT USE! Just for alignment purposes for now
typedef WORD hkHalf;

enum class CollisionGroup : short
{
    kAll,
    kPhysicalProxyPlayer,
    kPhysicalProxyCharacter,
    kHitCollider,
    kGroup4,
    kGroup5,
    kGroup6,
    kGroup7,
    kGroup8,
    kHighHit,
    kLowHitChr,
    kGroup11,
    kLowHitChrDamage,
    kGroup13,
    kSpecialHitKillplane,
    kSpecialHitCamera1,
    kSpecialHitEnemy,
    kSpecialHitCamera2,
    kGroup18,
    kGroup19,
    kGroup20,
    kGroup21,
    kGroup22,
    kGroup23,
    kGroup24,
    kGroup25,
    kDamage,
    kGroup27,
    kGroup28,
    kGroup29,
    kHitback,
    kGroup31,
    kGroup32,
    kGroup33,
    kGroup34,
    kGroup35,
    kGroup36,
    kGroup37,
    kGroup38,
    kGroup39,
    kGroup40,
    kGroup41,
    kGroup42,
    kBullet,
    kUnkBullet,
    kGroup45,
    kGroup46,
    kGroup47,
    kGroup48,
    kGroup49,
    kGroup50,
    kGroup51,
    kGroup52,
    kGroup53,
    kMapDamage,
    kNone,
    kGroup56,
    kGroup57,
    kGroup58,
    kGroup59,
    kGroup60,
    kGroup61,
    kGroup62,
    kGroup63
};

namespace Havok
{
    struct hkTransform {
        float m_rotation[12];
        hkVector4 m_translation;
    };

    struct hkQsTransform {
        hkVector4 m_translation;
        hkQuaternion m_rotation;
        hkVector4 m_scale;
    };

    struct hkSweptTransformf {
        hkVector4 m_centerOfMass0;
        hkVector4 m_centerOfMass1;
        hkVector4 m_rotation0;
        hkVector4 m_rotation1;
        hkVector4 m_centerOfMassLocal;
    };

    template <typename T>
    class hkArray {
    private:
        T* m_data;
        UINT m_size;
        UINT m_capacityAndFlags;

    public:
        UINT size() const { return this->m_size; }

        T at(size_t idx) 
        { 
            if (this->m_size > idx) return this->m_data[idx]; 

            throw("Access out of bound element for hkArray");
        }

        T* data() { return this->m_data; }
    };

    template <typename T>
    struct hkSmallArray {
        T* m_data;
        USHORT m_size;
        USHORT m_capacityAndFlags;
    };

    struct hkMultiThreadCheck {
        UINT m_threadId;
        int m_stackTraceId;
        USHORT m_markCount;
        USHORT m_markBitStack;
    };
}