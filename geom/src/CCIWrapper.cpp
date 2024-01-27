#include <CCIWrapper.h>
#include <IntTools_TopolTool.hxx>
#include <IntPatch_Intersection.hxx>

void CCIWrapper::Execute(const Handle(Adaptor3d_Surface) &cyl1, const Handle(Adaptor3d_Surface) &cyl2)
{
    auto ipi = IntPatch_Intersection();
    auto itt1 =	Handle(Adaptor3d_TopolTool)(new IntTools_TopolTool(cyl1));
    auto itt2 =	Handle(Adaptor3d_TopolTool)(new IntTools_TopolTool(cyl2));
    const Standard_Real tolArc = 0.1;
    const Standard_Real tolTang = 0.1;
    ipi.Perform(cyl1, itt1, cyl2, itt2, tolArc, tolTang);
    auto isDone = ipi.IsDone();
}