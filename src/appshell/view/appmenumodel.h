/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef MU_APPSHELL_APPMENUMODEL_H
#define MU_APPSHELL_APPMENUMODEL_H

#ifndef MU_QT5_COMPAT
Q_MOC_INCLUDE(< QWindow >)
#endif

#include "uicomponents/view/abstractmenumodel.h"

#include "modularity/ioc.h"
#include "ui/imainwindow.h"
#include "ui/iuiactionsregister.h"
#include "ui/inavigationcontroller.h"
#include "ui/iuiconfiguration.h"
#include "actions/iactionsdispatcher.h"
#include "workspace/iworkspacemanager.h"
#include "iappshellconfiguration.h"
#include "project/irecentfilescontroller.h"
#include "internal/iappmenumodelhook.h"
#include "extensions/iextensionsprovider.h"
#include "update/iupdateconfiguration.h"
#include "global/iglobalconfiguration.h"

namespace mu::appshell {
class AppMenuModel : public muse::uicomponents::AbstractMenuModel
{
    Q_OBJECT

    INJECT(muse::ui::IMainWindow, mainWindow)
    INJECT(muse::ui::IUiActionsRegister, uiActionsRegister)
    INJECT(muse::ui::INavigationController, navigationController)
    INJECT(muse::ui::IUiConfiguration, uiConfiguration)
    INJECT(muse::actions::IActionsDispatcher, actionsDispatcher)
    INJECT(muse::workspace::IWorkspaceManager, workspacesManager)
    INJECT(IAppShellConfiguration, configuration)
    INJECT(project::IRecentFilesController, recentFilesController)
    INJECT(IAppMenuModelHook, appMenuModelHook)
    INJECT(muse::extensions::IExtensionsProvider, extensionsProvider)
    INJECT(muse::update::IUpdateConfiguration, updateConfiguration)
    INJECT(muse::IGlobalConfiguration, globalConfiguration)

public:
    explicit AppMenuModel(QObject* parent = nullptr);

    Q_INVOKABLE void load() override;
    Q_INVOKABLE bool isGlobalMenuAvailable();

private:
    void setupConnections();

    using muse::uicomponents::AbstractMenuModel::makeMenuItem;
    muse::uicomponents::MenuItem* makeMenuItem(const muse::actions::ActionCode& actionCode, muse::uicomponents::MenuItemRole role);

    muse::uicomponents::MenuItem* makeFileMenu();
    muse::uicomponents::MenuItem* makeEditMenu();
    muse::uicomponents::MenuItem* makeViewMenu();
    muse::uicomponents::MenuItem* makeAddMenu();
    muse::uicomponents::MenuItem* makeFormatMenu();
    muse::uicomponents::MenuItem* makeToolsMenu();
    muse::uicomponents::MenuItem* makePluginsMenu();
    muse::uicomponents::MenuItemList makePluginsMenuSubitems();
    muse::uicomponents::MenuItem* makeHelpMenu();
    muse::uicomponents::MenuItem* makeDiagnosticMenu();

    muse::uicomponents::MenuItemList makeRecentScoresItems();
    muse::uicomponents::MenuItemList appendClearRecentSection(const muse::uicomponents::MenuItemList& recentScores);

    muse::uicomponents::MenuItemList makeNotesItems();
    muse::uicomponents::MenuItemList makeIntervalsItems();
    muse::uicomponents::MenuItemList makeTupletsItems();
    muse::uicomponents::MenuItemList makeMeasuresItems();
    muse::uicomponents::MenuItemList makeFramesItems();
    muse::uicomponents::MenuItemList makeTextItems();
    muse::uicomponents::MenuItemList makeLinesItems();
    muse::uicomponents::MenuItemList makeToolbarsItems();
    muse::uicomponents::MenuItemList makeWorkspacesItems();
    muse::uicomponents::MenuItemList makeShowItems();
    muse::uicomponents::MenuItemList makePluginsItems();
};
}

#endif // MU_APPSHELL_APPMENUMODEL_H
