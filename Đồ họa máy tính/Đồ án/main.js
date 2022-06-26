function init()
{
    var scene = new THREE.Scene()

    var box = getBox(1, 1, 1);
    var plane = getPlane(5)

    box.position.y = box.geometry.parameters.height/2;
    plane.rotation.x = Math.PI/2;

    scene.add(box);
    scene.add(plane);

    var camera = new THREE.PerspectiveCamera(60,window.innerWidth/ window.innerHeight,1,1000);

    camera.position.z = 6
    camera.position.x = 3
    camera.position.y = 2
    camera.lookAt(new THREE.Vector3(0, 0, 0));

    var renderer = new THREE.WebGLRenderer();
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.getElementById('webgl').appendChild(renderer.domElement);
    renderer.render(
        scene,
        camera
    );
}

//Tạo hình hộp
function getBox(w, h, d)
{
    var geometry = new THREE.BoxGeometry(1, 1, 1);
    var material = new THREE.MeshBasicMaterial({ color: 0xffccff });
    var mesh = new THREE.Mesh(geometry, material);

    return mesh;
}

//Tạo mặt phẳng
function getPlane(size)
{
    var geometry = new THREE.PlaneGeometry(size, size);
    var material = new THREE.MeshBasicMaterial({ color: 0xff0099, side: THREE.DoubleSide });
    var mesh = new THREE.Mesh(geometry, material);

    return mesh;
}

init();