/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TEACHERBARPLUGIN_H
#define TEACHERBARPLUGIN_H

#include <QObject>

#include "interfaces/IDockable.h"
#include "interfaces/IDocumentUser.h"
#include "interfaces/IBoardUser.h"
#include "interfaces/IMetaDataProvider.h"
#include "UBTGDockWidget.h"
#include "UBTGModel.h"


class TeacherBarPlugin : public QObject, IDockable, IDocumentUser, IBoardUser, IMetaDataProvider{
    Q_OBJECT
    Q_INTERFACES(IDockable IDocumentUser IBoardUser IMetaDataProvider)

public:
    TeacherBarPlugin();
    virtual UBDockPaletteWidget* dockableWidget();
    virtual void setDocument(IDocument *doc);
    virtual IDocument* document();
    virtual QObject* boardUser();
    virtual void save(QList<sNamespace> &ns, QList<sMetaData> &md);
    virtual QString nameSpace();
    virtual QString nameSpaceUrl();

public slots:
    virtual void onActiveSceneChanged();
    virtual void onActiveDocumentChanged();

private:
    void updateModel();

    UBTGDockWidget* mpDockWidget;
    UBTGModel* mpModel;
};

#endif // TEACHERBARPLUGIN_H
