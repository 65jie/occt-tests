/**
 * @file CCIWrapper.h
 * @brief Cylinder Cylinder Intersection Wrapper Class
 *
 * @author liuwujie (liuwujie@idea.edu.cn)
 * @date 2024-01-27
 */
#pragma once

#include <Adaptor3d_Surface.hxx>

class CCIWrapper
{
public:
    static void Execute(const Handle(Adaptor3d_Surface) &cyl1, const Handle(Adaptor3d_Surface) &cyl2);
};
