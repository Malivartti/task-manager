import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "pages/registration"
import "pages/authorization"
import "pages/main"

ApplicationWindow {
    id: window
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: "Task manager"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: authPage

        pushEnter: Transition {}
        pushExit: Transition {}
        popEnter: Transition {}
        popExit: Transition {}
        replaceEnter: Transition {}
        replaceExit: Transition {}
    }

    AuthorizationPage {
        id: authPage
        visible: true
        onToReg: {
            stackView.replace(regPage)
        }
        onLog_in: {
            stackView.replace(mainPage)
        }
    }

    RegistrationPage {
        id: regPage
        visible: false;
        onToAuth: {
            stackView.replace(authPage)
        }
        onSign_in: {
            stackView.replace(mainPage)
        }
    }

    MainPage {
        id: mainPage
        visible: false
    }

    Component.onCompleted: {
        regPage.sign_in.connect(mainPage.sign_in)
    }
}
