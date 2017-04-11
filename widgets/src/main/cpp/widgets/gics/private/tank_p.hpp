/****************************************************************************
**
** Copyright (C) 2009 TECHNOGERMA Systems France and/or its subsidiary(-ies).
** Contact: Technogerma Systems France Information (contact@technogerma.fr)
**
** This file is part of the GICS library.
**
** Commercial Usage
** Licensees holding valid GICS Commercial licenses may use this file in
** accordance with the GICS Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and TECHNOGERMA Systems France.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL3.txt included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at sales@technogerma.fr.
**
****************************************************************************/


#ifndef GICS_PRIVATE_TANK_HPP
#define GICS_PRIVATE_TANK_HPP

namespace gics
{
class Picture;

/**
 * \brief Private implementation of Tank
 */
class TankPrivate
{

public:

    /**
     * \brief update the foreground picture geometry
     */
    void updateForeground();

public:

    Picture* tankBackground; ///< Background picture of the tank
    Picture* tankForeground; ///< Picture of the tank filled part
    double value; ///< Tank doule value
    double minimum; ///< Minimum tank value
    double maximum; ///< Maximum tank value 
    Qt::Orientation orientation; ///< Tank orientation, vertical (default value) or horizontal

};

} // namespace gics

#endif // GICS_PRIVATE_TANK_HPP
