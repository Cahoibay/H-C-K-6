function init()
{
    var scene = new THREE.Scene();
    scene.fog = new THREE.FogExp2(0xffffff, 0.15);

    var box = getBox(1, 1, 1);
    var plane = getPlane(20);
    

    box.position.y = box.geometry.parameters.height / 2;
    box.rotation.x = Math.PI / 2;

    plane.rotation.x = Math.PI / 2;
    plane.name = 'plane-1';

    plane.add(box);
    plane.position.y = 0.5;
    
    scene.add(plane);

    var camera = new THREE.PerspectiveCamera(70,window.innerWidth/ window.innerHeight,1,1000);

    camera.position.x = 3.5;
    camera.position.y = 3;
    camera.position.z = 6;
    camera.lookAt(new THREE.Vector3(0, 0, 0));

    var renderer = new THREE.WebGLRenderer();
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setClearColor(0xffffff);
    document.getElementById('webgl').appendChild(renderer.domElement);
   
    update(renderer, scene, camera);
    return scene;
}

//Tạo hình hộp
function getBox(w, h, d)
{
    var geometry = new THREE.BoxGeometry(1, 1, 1);
    var material = new THREE.MeshBasicMaterial({ color: 0xFF0099});
    var mesh = new THREE.Mesh(geometry, material);

    return mesh;
}

function update(renderer, scene, camera)
{
    renderer.render(
        scene,
        camera
    );


    //Phép quay theo trục x,y,z của box
    var plane = scene.getObjectByName('plane-1');
    //plane.rotation.x += 0.01;
    //plane.rotation.y += 0.01;
    //plane.rotation.z += 0.01;

    //Phép tỷ lệ theo trục x của box
    plane.traverse(function (child) {
        child.scale.z += 0.01;
    })

    /*Phép tịnh tiến theo trục x của box
    plane.position.x += 0.01;*/

    requestAnimationFrame(function () {
        update(renderer, scene, camera);
    })
}

//Tạo mặt phẳng
function getPlane(size)
{
    var geometry = new THREE.PlaneGeometry(size, size);
    var material = new THREE.MeshBasicMaterial({ color: 0xFF99CC, side: THREE.DoubleSide });
    var mesh = new THREE.Mesh(geometry, material);

    return mesh;
}

var scene = init();