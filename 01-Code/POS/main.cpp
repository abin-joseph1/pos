#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "displaymodelmanager.h"
#include "connection.h"
#include "billmanager.h"
#include "settingsmodel.h"
#include "printmanager.h"
#include "paytypeviewmodel.h"

#include <QQmlContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qml);
    QGuiApplication app(argc, argv);

    if (!createConnection())
    {
        return 1;
    }

//    SettingsModel mSettingsModel = SettingsModel::getInstance();
    DisplayModelManager displayModelManager;
    BillManager billMgr;
    PrintManager printMgr;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("displayModelManager", &displayModelManager);
    engine.rootContext()->setContextProperty("groupModel",          displayModelManager.getGroupViewModel());
    engine.rootContext()->setContextProperty("subGroupModel",       displayModelManager.getSubGroupViewModel());
    engine.rootContext()->setContextProperty("itemModel",           displayModelManager.getItemViewModel());
    engine.rootContext()->setContextProperty("itemUnitsModel",      displayModelManager.getItemUnitsViewModel());

    PayTypeViewModel payTypeViewModel;
    engine.rootContext()->setContextProperty("payTypeViewModel",      &payTypeViewModel);

    engine.rootContext()->setContextProperty("billManager", &billMgr);
    engine.rootContext()->setContextProperty("billItemsModel", billMgr.getItemModel());

    engine.rootContext()->setContextProperty("printManager", &printMgr);

//    engine.rootContext()->setContextProperty("settings", SettingsModel::getInstance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //qDebug() << Q_FUNC_INFO << "start" << billMgr.getGroupViewModel()->rowCount();

    return app.exec();
}
