/*************************************************************************
**
**  MG-APP----Multi-GNSS-Automatic Precise Positioning Software
**  Copyright (C) 2016-2020 XiaoGongWei
**  This file is part of MG-APP.
**
**  GNU Lesser General Public License Usage
**  Alternatively, this file may be used under the terms of the GNU Lesser
**  General Public License version 3 as published by the Free Software
**  Foundation and appearing in the file LICENSE.LGPL3 included in the
**  packaging of this file. Please review the following information to
**  ensure the GNU Lesser General Public License version 3 requirements
**  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
**  MPL License Usage
**  This Source Code Form is subject to the terms of the Mozilla Public
**  License, v. 2.0. If a copy of the MPL was not distributed with this
**  file, You can obtain one at http://mozilla.org/MPL/2.0/.
**
**  GPLv3.0 License Usage
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see http://www.gnu.org/licenses/.
**
**  BSD 2-clause
**  Copyright(c) 2007‐2013, T.Takasu, All rights reserved
**  Redistribution and use in source and binary forms, with or without modification,
**  permitted provided that the following conditions are met:
**  1. Redistributions of source code must retain the above copyright notice,
**  this list of conditions and the following disclaimer.
**  2. Redistributions in binary form must reproduce the above copyright notice,
**  this list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
**  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
**  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
**  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
**  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
**  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
**  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
**  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
**  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**************************************************************************
**           Author: XiaoGongWei
**   Website: github.com/xiaogongwei/MG_APP
** Download link (The GPS Toolbox): https://www.ngs.noaa.gov/gps-toolbox/
**             Date: 06.02.2020
****************************************************************************/

#ifndef QBASEOBJECT_H
#define QBASEOBJECT_H

#include <QString>
#include <QDebug>
/*
1.  illustration:
QString tempLine = "G";
char tempSatType = '0';
tempSatType = *(tempLine.mid(0,1).toLatin1().data());//convert qstring to char

*/


class QBaseObject
{
//public functions
public:
    enum PPP_MODEL    {
        PPP_Combination = 0,
        PPP_NOCombination = 1
    };
	QBaseObject(void);
	~QBaseObject(void);
    //set satilite system SystemStr:"G"( open GPS system);"GR":(open GPS+GLONASS system);"GRCE"(open all system)
    bool setSatlitSys(QString SystemStr);//GPS, GLONASS, BDS and Galieo use the letters G, R, C and E respectively.
    QString getSatlitSys();//GPS, GLONASS, BDS and Galieo use the letters G, R, C and E respectively.
    bool isInSystem(char Sys);//Systeam: G R C (representing GPS, GLONASS, BDS) determines whether the system data is needed
    int getSystemnum();//Get the current settings for several systems
    void setPPPModel(PPP_MODEL _PPP_MODEL) {m_PPP_MODEL = _PPP_MODEL;}
    PPP_MODEL getPPPModel() {return m_PPP_MODEL;}
    QString getSaveFloderName() {return m_floder_name;}
private:
    void initVar();//Initialize data (GPS is turned on by default)
//Data section
protected:
    //Join System Judgment
    bool IsaddGPS;//Whether to add GPS (default on)
    bool IsaddGLOSS;//Whether to add GLONASS or not
    bool IsaddBDS;//Whether to join Beidou
    bool IsaddGalieo;//Whether to join Galieo or not
    QString m_SystemStr;//GPS, GLONASS, BDS and Galieo use the letters G, R, C and E respectively.
    int m_SystemNum;
    PPP_MODEL m_PPP_MODEL;
    QString m_floder_name;
private:
};

#endif
