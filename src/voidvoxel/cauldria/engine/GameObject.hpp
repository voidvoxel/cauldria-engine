#if !defined(VOIDVOXEL__CAULDRIA__GAME_OBJECT_HPP)
#define VOIDVOXEL__CAULDRIA__GAME_OBJECT_HPP

namespace voidvoxel::cauldria
{
    class GameObject
    {
    public:
        GameObject();
        ~GameObject();
        void render();
        void tick();
    };
}

#endif // VOIDVOXEL__CAULDRIA__GAME_OBJECT_HPP
