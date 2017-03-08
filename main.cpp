
#include <gl/glut.h> 
#include <osgViewer/Viewer> 
#include <osgText/Text> 
osg::Node* CreateScene()
{
	// Cr�ation d'un n�ud et d�sactivation de la lumi�re pour celui-ci
	osg::Geode* geode = new osg::Geode();
	osg::StateSet* stateset = geode->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	// Cr�ation d'une projection orthographique afin d'avoir le texte align� � l'�cran
	osg::Camera* camera = new osg::Camera;
	camera->setProjectionMatrix(osg::Matrix::ortho2D(0, 512, 0, 512));
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setViewMatrix(osg::Matrix::identity());
	camera->addChild(geode);

	// Cr�ation d'un texte et ajout au noeud
	osgText::Text* text = new osgText::Text;
	geode->addDrawable(text);

	// D�finit les donn�es du texte
	text->setPosition(osg::Vec3(16.f, 16.0f, 0.0f));
	text->setColor(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
	text->setText("Hello World");

	return camera;
}

int main(void)
{
	// Construit le viewer
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	// Cr�er une fen�tre 512x512 et la positionner en 32, 32
	viewer->setUpViewInWindow(32, 32, 512, 512);

	// D�finit les donn�es de sc�ne que le viewer dessinera
	viewer->setSceneData(CreateScene());

	// Ex�cute la boucle principale
	return viewer->run();
}