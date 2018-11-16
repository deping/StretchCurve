#include "stdafx.h"

//#include <algorithm>
#include <numeric>
#include "IPlanarCurve.h"
#include "PickHandler.h"

void EnableEdit(osgViewer::View * pView, double offset)
{
    if (!pView)
        return;
    auto pNode = pView->getSceneData();
    if (!pNode)
        return;
    auto handlers = pView->getEventHandlers();
    for (auto handler : handlers)
    {
        auto picker = dynamic_cast<PickHandler*>(handler.get());
        if (picker)
        {
            return;
        }
    }
    pView->addEventHandler(new PickHandler(pView, offset));
}
