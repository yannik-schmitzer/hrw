#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QString>
#include <QObject>
#include <QAbstractGraphicsShapeItem>

class GraphicsObject : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     * @param parent is the hierarchical preciding object and null by default.
     */
    explicit GraphicsObject(QObject *parent = nullptr);
    /**
     * @brief Returns the object's name (i.e. object_1).
     * @return The name.
     */
    QString name() const;
    /**
     * @brief Sets the object's name.
     * @param name is the desired name.
     */
    void setName(const QString &name);
    /**
     * @brief Pure virtual method, which has to be implemented in Child classes.
     * @return A drawable object.
     */
    virtual QAbstractGraphicsShapeItem *graphicsShapeItem() const = 0;
    /**
     * @brief Creates a readable object representation.
     * @return A QString with the object's properties.
     */
    virtual QString toString();
protected:
    /**
     * @brief Holds the object's name.
     */
    QString m_name;
    /**
     * @brief Classes' instance counter.
     */
    static unsigned long m_graphicsObjectCounter;
};

#endif // GRAPHICSOBJECT_H
