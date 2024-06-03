import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "page" as Pages

Window {
    width: 1344
    height: 756
    minimumWidth: 960
    minimumHeight: 540
    visible: true
    title: qsTr("Task Manager")

    function toMain(user) {
        pageView.replace(mainPage)
        mainPage.enable(user)
    }

    StackView {
        id: pageView
        anchors.fill: parent
        initialItem: authPage

        pushEnter: Transition {}
        pushExit: Transition {}
        popEnter: Transition {}
        popExit: Transition {}
        replaceEnter: Transition {}
        replaceExit: Transition {}
    }

    Pages.MainPage {
        id: mainPage
        visible: false
    }

    Pages.AuthPage {
        id: authPage
        visible: false
    }

    Component.onCompleted: {
        authPage.toMain.connect(toMain)
    }
}
