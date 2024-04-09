import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    id: page
    signal toHome();
    signal toProjects();
    signal toAccount();

    Button {
        text: "Главная"
        onClicked: {
            page.toHome();
        }
    }

    Button {
        text: "Проекты"
        onClicked: {
            page.toProjects();
        }
    }

    Button {
        text: "Аккаунт"
        Layout.alignment: Qt.AlignRight
        onClicked: {
            page.toAccount();
        }
    }
}
