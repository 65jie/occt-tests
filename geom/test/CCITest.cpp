#include <gtest/gtest.h>
#include <CCIWrapper.h>
#include <GeomAdaptor_Surface.hxx>
#include <Geom_CylindricalSurface.hxx>

TEST(CCITest, Test_1)
{
	Handle(Geom_CylindricalSurface) cyl1(new Geom_CylindricalSurface(
		gp_Ax3(), 100));
	Handle(Geom_CylindricalSurface) cyl2(new Geom_CylindricalSurface(
		gp_Ax3(gp_Pnt(100, 0, 0), gp_Dir(0, 1, 0), gp_Dir(1, 0, 0)), 50));
	Handle(Adaptor3d_Surface) aCyl1(new GeomAdaptor_Surface(cyl1));
	Handle(Adaptor3d_Surface) aCyl2(new GeomAdaptor_Surface(cyl2));
	EXPECT_NO_THROW(CCIWrapper::Execute(aCyl1, aCyl2));
}