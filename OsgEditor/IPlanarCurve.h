#pragma once
#include <set>
#include <list>

#include <osg/Geode>
#include <osg/NodeCallback>
#include <osg/OperationThread>
#include <osgViewer/View>

#include <osgeditor_export.h>

enum class GripType : char
{
    End,
    Mid,
    Cen,
    Ctl
};

struct GripPoint
{
    osg::Vec2 point;
    GripType type;
};

struct IPlanarCurve
{
    virtual bool nearest(const osg::Vec2d & localPt, osg::Vec2d& nearest) const = 0;
    virtual void getHandles(std::vector<GripPoint>& points) const = 0;
    // pos is in local coordinate system.
    virtual void stretch(int index, GripType type, const osg::Vec2d& pos) = 0;
};

const osg::Node::NodeMask HANDLE_NODE_MASK = 0x40000;

void EnableStretch(osgViewer::View* pView, double offset = 5);
