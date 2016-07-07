//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// StructScreen.h:
// Rob McDonald
//////////////////////////////////////////////////////////////////////

#if !defined(VSP_STRUCTSCREEN_H_INCLUDED_)
#define VSP_STRUCTSCREEN_H_INCLUDED_

#include "ScreenBase.h"
#include "GuiDevice.h"
#include "Vehicle.h"
#include "ScreenMgr.h"
#include "FeaPart.h"

#include <deque>
using namespace std;


class StructScreen : public TabScreen
{
public:
	StructScreen( ScreenMgr* mgr );
    virtual ~StructScreen();

    virtual void Show();

    virtual void GuiDeviceCallBack( GuiDevice* device );

    virtual void CallBack( Fl_Widget* w );
    virtual void CloseCallBack( Fl_Widget *w );

    static void staticScreenCB( Fl_Widget *w, void* data )
    {
        ( ( StructScreen* )data )->CallBack( w );
    }

    void AddOutputText( const string &text );

    string truncateFileName( const string &fn, int len );

    bool Update();

    void LoadDrawObjs( vector< DrawObj* > &draw_obj_vec );

private:
    Fl_Text_Buffer m_TextBuffer;

    GroupLayout m_GlobalTabLayout;
    GroupLayout m_OutputTabLayout;
    GroupLayout m_ConsoleLayout;
    GroupLayout m_BorderConsoleLayout;

    GroupLayout m_StructureTabLayout;
    TabGroup m_ComponentGroup;
    GroupLayout m_RibTabLayout;
    GroupLayout m_RibEditLayout;
    GroupLayout m_SparTabLayout;
    GroupLayout m_UpSkinTabLayout;
    GroupLayout m_LowSkinTabLayout;
    GroupLayout m_PtMassTabLayout;

    //===== Console Items =====//

    Fl_Text_Display *m_ConsoleDisplay;
    Fl_Text_Buffer *m_ConsoleBuffer;

    //===== Global Tab Items =====//

    SliderAdjRangeInput m_MaxEdgeLen;
    SliderAdjRangeInput m_MinEdgeLen;
    SliderAdjRangeInput m_MaxGap;
    SliderAdjRangeInput m_NumCircleSegments;
    SliderAdjRangeInput m_GrowthRatio;
    SliderAdjRangeInput m_ThickScale;

    ToggleButton m_Rig3dGrowthLimit;
    ToggleButton m_IntersectSubsurfaces;

    TriggerButton m_GlobSrcAdjustLenLftLft;
    TriggerButton m_GlobSrcAdjustLenLft;
    TriggerButton m_GlobSrcAdjustLenRht;
    TriggerButton m_GlobSrcAdjustLenRhtRht;
    TriggerButton m_GlobSrcAdjustRadLftLft;
    TriggerButton m_GlobSrcAdjustRadLft;
    TriggerButton m_GlobSrcAdjustRadRht;
    TriggerButton m_GlobSrcAdjustRadRhtRht;

    Choice m_UseSet;

    //===== Output Tab Items =====//

    ToggleButton m_StlFile;
    ToggleButton m_MassFile;
    ToggleButton m_NastFile;
    ToggleButton m_GeomFile;
    ToggleButton m_ThickFile;

    TriggerButton m_SelectStlFile;
    TriggerButton m_SelectMassFile;
    TriggerButton m_SelectNastFile;
    TriggerButton m_SelectGeomFile;
    TriggerButton m_SelectThickFile;

    StringOutput m_StlOutput;
    StringOutput m_MassOutput;
    StringOutput m_NastOutput;
    StringOutput m_GeomOutput;
    StringOutput m_ThickOutput;

    //===== Structure Tab Items =====//
    IndexSelector m_SectSel;

    //===== Rib =====//
    IndexSelector m_RibSel;

    TriggerButton m_AddRib;
    TriggerButton m_DelRib;

    SliderAdjRangeInput m_RibThickSlider;
    SliderAdjRangeInput m_RibDensitySlider;

    SliderAdjRangeInput m_RibPosSlider;
    SliderAdjRangeInput m_RibSweepSlider;

    ToggleButton m_RibTrimButton;

    ToggleButton m_RibSweepAbsButton;
    ToggleButton m_RibSweepRelButton;
    ToggleRadioGroup m_RibSweepToggle;

    //===== Common buttons =====//

    TriggerButton m_ExportFEAMeshButton;
    TriggerButton m_ComputeFEAMeshButton;
    ToggleButton m_DrawMeshButton;


};

#endif
