/*! \verbatim
*  \copyright      Copyright (c) 2015 Technische Universität München
*                  Chair of Computational Modeling and Simulation. All rights reserved.
*  \author         Alexander Widner <ga96heq@mytum.de> (https://www.cms.bgu.tum.de)
*  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief          This file is part of the TUM Open Infra Platform.
*  \endverbatim
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#pragma once

#include <QAPPLICATION>
#include <QDialog>
#include "OpenInfraPlatform/DataManagement/Data.h"
#include "buw.BlueApplication.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DClothoid_old.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/VerticalAlignment/VerticalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/Alignment2DBased3D.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DLine.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/HorizontalAlignment/HorizontalAlignmentElement2DArc.h"


buw::vector2d relCloEnd(double L, double A, int sig);
buw::vector2d absCloEnd(buw::vector2d startPoint, buw::vector2d cloth_start_dir, double L, double A, int sig);
buw::vector2d computeIntersectionArcArc(buw::vector2d rm1, buw::vector2d rm2, double R1, double R2, bool clockofR1);
int isClothoidInBorder(double tau1, double tau2, double border, std::string&);
int isU1U2SmallerLength(double u1, double u2, double length2, std::string&);
int isU3U4SmallerLength(double u3, double u4, double length3, std::string&);
int are2Points(int size, std::string&);
int are3_4or5Points(int size, std::string&);
int isIntersectionArcArc(buw::vector2d rm1, buw::vector2d rm2, double R1, double R2, std::string&);
int isAngleInBorders(double phi1, double phi2, std::string&);
int isInsertNotZero(double Insert1, double Insert2, double Insert3, std::string&);
int areErrorsForParallelArc(double Rmin, double width, std::string&);
int isInsertZero(double V1, double V2, double V3, double V4, double V5, double V6, std::string&);
int areErrorsForParallelClo(double L, double A, double width, double distance, bool UseNoLines, std::string&);
void insertA_for_ACCA2(double &AA1, double &AA2, double &A1, double &A2, double &Atest);
void make2ClothByConnectLin(double, double, double, double, double, buw::vector2d, buw::vector2d, int, buw::vector2d, buw::vector2d);
void make3DLine(buw::ReferenceCounted<buw::HorizontalAlignment2D> ha);
void makeClothoid(double R1, double R2, double A, buw::vector2d startPoint, buw::vector2d cloth_start_dir, bool clockwise);
void makeArc(buw::vector2d, buw::vector2d, buw::vector2d, bool);
void compute_L_tau(double &, double &, double &, double &, double, double, double, double);
void give2Points(buw::vector2d &, buw::vector2d &, buw::vector2d &, buw::vector2d, buw::vector2d, buw::vector2d);
void give3Points(buw::vector2d &, buw::vector2d &, buw::vector2d &, buw::vector2d &, buw::vector2d &, double &, double &, double &, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d);
void ClothByConnectLin(buw::vector2d &, buw::vector2d &, buw::vector2d &, buw::vector2d &, double&, double&, double&, double&, int&, buw::vector2d, buw::vector2d&);
void parallelClo(buw::vector2d &, buw::vector2d &, double &, double &, double &, double &, double, double, double, buw::vector2d, buw::vector2d, int);
void GeneralArcClothoidArc(buw::vector2d, buw::vector2d, bool, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, double, double, bool, double, double, double, double);
void GeneralArcClothoidClothoidArc(buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, buw::vector2d, double, double, bool, int, double, double, double, double, double, double);
void GeneralLine_Arc_Arc_Arc_Line(int, int, double, double, double, double, bool, buw::vector2d, buw::vector2d, buw::vector2d, std::vector<buw::vector2d>, std::vector<buw::vector2d>, std::vector<buw::vector2d>, std::vector<buw::vector2d>);
void makePizza(buw::vector2d start1, buw::vector2d start2, buw::vector2d end1, buw::vector2d end2, buw::vector2d center1, buw::vector2d center2);
void makeOne3dLine(buw::vector2d &start1, buw::vector2d &start2);
void swapThatLargerFirst(double &A, double &B);
double iteration_ACA(double, double, double);
double iteration_ACCA(double, double, double, double);

#endif
