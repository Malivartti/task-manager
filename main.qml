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
        visible: false
        onToRegistrationPage: {
            stackView.replace(regPage)
        }
        onToMainPage: {
            stackView.replace(mainPage)
        }
    }

    RegistrationPage {
        id: regPage
        visible: false;
        onToAuthorizationPage: {
            stackView.replace(authPage)
        }
        onToMainPage: {
            stackView.replace(mainPage)
        }
    }

    MainPage {
        id: mainPage
        visible: false
    }

    Component.onCompleted: {
        regPage.toMainPage.connect(mainPage.setUserId)
        authPage.toMainPage.connect(mainPage.setUserId)
    }
}
