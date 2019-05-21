/****************************************************************************
**
** Copyright (C) 2016 LG Electronics, Inc., author: <mikko.levonmaa@lge.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "testkeyboardgrabber.h"

TestKeyboardGrabber::TestKeyboardGrabber(QWaylandSeat *seat)
    : QWaylandKeyboard(seat)
{
}

void TestKeyboardGrabber::setFocus(QWaylandSurface *surface)
{
    Q_EMIT focusedCalled();
    QWaylandKeyboard::setFocus(surface);
}

void TestKeyboardGrabber::sendKeyPressEvent(uint code, bool repeat)
{
    Q_EMIT keyPressCalled();
    QWaylandKeyboard::sendKeyPressEvent(code, repeat);
}

void TestKeyboardGrabber::sendKeyReleaseEvent(uint code, bool repeat)
{
    Q_EMIT keyReleaseCalled();
    QWaylandKeyboard::sendKeyReleaseEvent(code, repeat);
}

void TestKeyboardGrabber::sendKeyModifiers(QWaylandClient *client, uint32_t serial)
{
    Q_EMIT modifiersCalled();
    QWaylandKeyboard::sendKeyModifiers(client, serial);
}
