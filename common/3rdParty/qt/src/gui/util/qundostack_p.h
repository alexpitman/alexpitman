/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QUNDOSTACK_P_H
#define QUNDOSTACK_P_H

#include <private/qobject_p.h>
#include <QtCore/qlist.h>
#include <QtCore/qstring.h>
#include <QtGui/qaction.h>

#include "qundostack.h"

QT_BEGIN_NAMESPACE
class QUndoCommand;
class QUndoGroup;

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
// file may change from version to version without notice, or even be removed.
//
// We mean it.
//

class QUndoCommandPrivate
{
public:
    QUndoCommandPrivate() : id(-1) {}
    QList<QUndoCommand*> child_list;
    QString text;
    int id;
};

#ifndef QT_NO_UNDOSTACK

class QUndoStackPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QUndoStack)
public:
    QUndoStackPrivate() : index(0), clean_index(0), group(0), undo_limit(0) {}

    QList<QUndoCommand*> command_list;
    QList<QUndoCommand*> macro_stack;
    int index;
    int clean_index;
    QUndoGroup *group;
    int undo_limit;

    void setIndex(int idx, bool clean);
    bool checkUndoLimit();
};

#ifndef QT_NO_ACTION
class QUndoAction : public QAction
{
    Q_OBJECT
public:
    QUndoAction(const QString &prefix, QObject *parent = 0);
public Q_SLOTS:
    void setPrefixedText(const QString &text);
private:
    QString m_prefix;
};
#endif // QT_NO_ACTION


QT_END_NAMESPACE
#endif // QT_NO_UNDOSTACK
#endif // QUNDOSTACK_P_H
