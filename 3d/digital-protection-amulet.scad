$fn=36;

translate([1.25,0,-2]) pcb();
difference() {
    union() {
        superior();
        inferior();
    }
    *union() {
        translate([-2,-5,-5]) cube([80,20,20]);
        translate([14,-5,-5]) cube([80,40,20]);
    }
}

module superior() {
    difference() {
        union() {
            hull() {
                translate([0,2.5,0]) rotate([0,90,0]) cylinder(r=5, h=1);
                translate([0,17.5,0]) rotate([0,90,0]) cylinder(r=5, h=1);
                translate([55,2.5,0]) sphere(r=5);
                translate([55,17.5,0]) sphere(r=5);
            }
            translate([60,10,0]) rotate([0,0,-90]) scale([2,1,1.5]) rotate_extrude(convexity = 10) translate([2.5, 0, 0]) circle(r = 0.75);
        }
        union() {
            //silueta
            translate([-1,-3.5,4]) cube([60,27,2]);
            difference() {
                translate([-1,-3.5,-6]) cube([65,27,6]);
                union() {
                    translate([10,-0,-0.2]) cube([1,1,3]);
                    translate([10,19,-0.2]) cube([1,1,3]);
                }
            }
            //interior
            difference() {
                hull() {
                    translate([1,2.5,0]) rotate([0,90,0]) cylinder(r=4, h=1);
                    translate([1,17.5,0]) rotate([0,90,0]) cylinder(r=4, h=1);
                    translate([55,2.5,0]) sphere(r=4);
                    translate([55,17.5,0]) sphere(r=4);
                }
                translate([-1,-3.5,3]) cube([60,27,2]);
                //sujecion pcb
                union() {
                    translate([10,-2.25,-1]) cube([1,3,4]);
                    translate([10,19.25,-1]) cube([1,3,4]);
                    difference() {
                        union () {
                            translate([52.25,10,0]) cylinder(r=2.25,h=5);
                            translate([52.25,10,2]) cylinder(r1=2.25,r2=2.75,h=1);
                        }
                        union() {
                            translate([52.25,10,-1]) cylinder(r=1.2,h=5);
                        }
                    }
                }
                //pestañas
                translate([1,1.2,1.8]) hull() {
                    cube([1,2.6,0.3]);
                    translate([0,0,-0.8]) cube([0.1,2.6,0.1]);
                }
                translate([1,16.2,1.8]) hull() {
                    cube([1,2.6,0.3]);
                    translate([0,0,-0.8]) cube([0.1,2.6,0.1]);
                }
            }
            //borde cierre
            difference() {
                hull() {
                    translate([0.4,-2.5+0.4,-1]) cube([1,24.2,2]);
                    translate([55,2.5,-1]) cylinder(r=4.6, h=2);
                    translate([55,17.5,-1]) cylinder(r=4.6, h=2);
                }
                hull() {
                    translate([2,0,-1]) cube([1,20,2]);
                    translate([55,2.5,-1]) cylinder(r=2.5, h=2);
                    translate([55,17.5,-1]) cylinder(r=2.5, h=2);
                }
            }
            //decoracion
            translate([0,-2.5,3.8]) linear_extrude(1) import("superior.svg");
            translate([0.2,5,-3]) rotate([90,0,-90]) linear_extrude(1) import("duck.svg");
            //tornillo
            translate([52.25,10,0]) cylinder(r=1.2,h=5);
            translate([52.25,10,1.7]) cylinder(r1=1.2,r2=2,h=1.8);
            translate([52.25,10,3.45]) cylinder(r=2,h=2);
            //usb
            translate([-0.5,6.1-0.25,-0.55-0.25]) cube([2,8.5,3.5]);
            //led
            translate([35.814+1.25,20-9.906,0]) cylinder(r=1, h=3.5);
            translate([35.814+1.25,20-9.906,0]) cylinder(r=0.25, h=5);
        }
    }
}

module inferior() {
    difference() {
        union() {
            hull() {
                translate([0,2.5,0]) rotate([0,90,0]) cylinder(r=5, h=1);
                translate([0,17.5,0]) rotate([0,90,0]) cylinder(r=5, h=1);
                translate([55,2.5,0]) sphere(r=5);
                translate([55,17.5,0]) sphere(r=5);
            }
            translate([60,10,0]) rotate([0,0,-90]) scale([2,1,1.5]) rotate_extrude(convexity = 10) translate([2.5, 0, 0]) circle(r = 0.75);
        }
        union() {
            //silueta
            translate([-1,-3.5,-6]) cube([60,27,2]);
            difference() {
                translate([-1,-3.5,0.8]) cube([65,27,6]);
                //pestañas
                union() {
                    translate([1.1,0,0]) cube([2,5,2.75]);
                    translate([1.1,15,0]) cube([2,5,2.75]);
                }
            }
            //interior
            difference() {
                hull() {
                    translate([1,2.5,0]) rotate([0,90,0]) cylinder(r=4, h=1);
                    translate([1,17.5,0]) rotate([0,90,0]) cylinder(r=4, h=1);
                    translate([55,2.5,0]) sphere(r=4);
                    translate([55,17.5,0]) sphere(r=4);
                }
                translate([-2,-3.5,-5]) cube([62,27,2]);
                //sujeccion pcb
                union() {
                    for(i=[5:10:45]) {
                        translate([i,-2.25,-3]) difference() {
                            cube([1,5,2]);
                            translate([-0.5,2,1]) cube([2,4,2]);
                        }
                        translate([i,17.25,-3]) difference() {
                            cube([1,5,2]);
                            translate([-0.5,-1,1]) cube([2,4,2]);
                        }
                        translate([i,8.5,-3]) cube([1,3,1]);
                    }
                    for(i=[6:7:15]) {
                        translate([53.5,i,-3]) difference() {
                            cube([6,1,2]);
                            translate([-1,-0.5,1]) cube([4,2,2]);
                        }
                    }
                    difference() {
                        translate([56.25,0,-3]) cylinder(r=2.75,h=3);
                        union() {
                            translate([56.25,0,-4]) cylinder(r=2.25,h=5);
                        }
                    }
                    difference() {
                        translate([56.25,20,-3]) cylinder(r=2.75,h=3);
                        union() {
                            translate([56.25,20,-4]) cylinder(r=2.25,h=5);
                        }
                    }
                    difference() {
                        union () {
                            translate([52.25,10,-3]) cylinder(r=2.5,h=1);
                            translate([52.25,10,-3]) cylinder(r=1.5,h=2.8);
                        }
                        union() {
                            translate([52.25,10,-4]) cylinder(r=0.75,h=5);
                        }
                    }
                }
                //pestañas
                difference() {
                    union() {
                        translate([1,0,0]) cube([1,5,2.75]);
                        for(i=[ 0,4,15,19 ]) {
                            translate([0,i,0]) hull() {
                                translate([1,0,0]) cube([1,1,2.75]);
                                translate([1,0.3,1]) cube([1.5,0.4,1.75]);
                            }
                        }
                        translate([1,0,0]) hull() {
                            cube([1,5,1]);
                            translate([0,-0.8,0]) cube([0.1,6.6,1]);
                        }
                        translate([1,-1,0]) hull() {
                            cube([1,1,1]);
                            translate([0,-0.5,0]) cube([3,0.1,1]);
                        }
                        translate([1,15,0]) cube([1,5,2.75]);
                        translate([1,15,0]) hull() {
                            cube([1,5,1]);
                            translate([0,-0.8,0]) cube([0.1,6.6,1]);
                        }
                        translate([1,20,0]) hull() {
                            cube([1,1,1]);
                            translate([0,1.5,0]) cube([3,0.1,1]);
                        }
                    }
                    union() {
                        translate([0,-1,0.8]) cube([1.25,7,2.75]);
                        translate([0,1,1]) cube([3,3,1.25]);
                        translate([0,14,0.8]) cube([1.25,7,2.75]);
                        translate([0,16,1]) cube([3,3,1.25]);
                    }
                }
            }
            //borde cierre
            difference() {
                hull() {
                    translate([-1,-2.5,0]) cube([1,25,2]);
                    translate([58,2.5,0]) cylinder(r=5.5, h=2);
                    translate([58,17.5,0]) cylinder(r=5.5, h=2);
                }
                hull() {
                    translate([0.6,-1.8,-1]) cube([1,23.6,4]);
                    translate([55,2.5,-1]) cylinder(r=4.4, h=4);
                    translate([55,17.5,-1]) cylinder(r=4.4, h=4);
                }
            }
            //decoracion
            translate([0,-2.5+25,-4.8]) mirror([0,1,0]) linear_extrude(1) import("inferior.svg");
            translate([0.2,5,-3]) rotate([90,0,-90]) linear_extrude(1) import("duck.svg");
            //usb
            translate([-0.5,6.1-0.25,-0.55-0.25]) cube([2,8.5,3.5]);
        }
    }
}

module pcb() {
    difference() {
        union() {
            color("forestgreen") cube([55,20,1.6]);
            //top side components
            translate([0,0,1.6]) union() {
                //10118194
                translate([2.794, (20 - 9.906), 0]) rotate([0,0,-90]) union() {
                    color("silver") translate([-3.55,-2.5,0]) cube([7.1,5,2.4]);
                    color("silver") translate([-4,-3.03,-0.15]) cube([8,0.53,3]);
                    color("lightgray") for(i = [-3.5,3.5] ) {
                        translate([i - 0.1,-0.8,-0.6]) cube([0.2,0.9,0.6]);
                    }
                    color("lightgray") for(i = [-2.5,2.5] ) {
                        translate([i - 0.3,2.3,-0.6]) cube([0.6,0.2,0.6]);
                    }
                    color("lightgray") for(i = [-1.3:0.65:1.3] ) {
                        translate([i - 0.125,2.3,0]) cube([0.25,0.6,0.2]);
                    }
                }
                //TQFP44
                translate([20.574, (20 - 9.906), 0]) rotate([0,0,45]) union() {
                    color("dimgrey") translate([-5, -5, 0]) cube([10, 10, 1.2]);
                    color("lightgray") for (i = [-4.215:0.8:4.1]) {
                        translate([-6, i, 0]) cube([12, 0.37, 0.15]);
                        translate([i, -6, 0]) cube([0.37, 12, 0.15]);
                    }
                }
                //TSOP6
                translate([9.144, (20 - 4.572), 0]) union() {
                    color("dimgrey") translate([-0.75, -1.5, 0]) cube([1.5, 3, 1.1]);
                    color("lightgray") for (i = [-0.95, 0,0.95]) {
                        translate([-1.375, i - 0.25, 0]) cube([2.75, 0.5, 0.26]);
                    }
                }
                //PLCC4 2x2
                translate([35.814, (20 - 9.906), 0]) rotate([0,0,90]) union() {
                    color("snow") translate([0, 0, 0.8]) cylinder(r=0.75, h=0.2);
                    color("ivory") translate([-1, -1, 0]) cube([2, 2, 0.9]);
                    color("lightgray") for (i = [-0.8, 0.8]) {
                        translate([i - 0.3, -0.75, 0]) cube([0.6, 0.55, 0.45]);
                        translate([i - 0.3, 0.2, 0]) cube([0.6, 0.55, 0.45]);
                    }
                }
                //XTAL
                translate([12.954, (20 - 17.018), 0]) rotate([0,0,90]) union() {
                    color("silver") translate([-1.25, -1, 0]) cube([2.5, 2, 0.5]);
                }
                //1210 F
                translate([3.048, (20 - 4.064), 0]) union() {
                    color("slategray") translate([-1, -1.25, 0]) cube([2, 2.5, 0.45]);
                    color("lightgray") for (i = [-1.25, 1.25]) {
                        translate([i - 0.25, -1.25, 0]) cube([0.5, 2.5, 0.5]);
                    }
                }
                //0805 R
                for (i = [ [35.56, (20 - 7.112), 0], [32.004, (20 - 11.176), 0], [32.004, (20 - 13.462), 0], [32.004, (20 - 15.748), 0], [32.004, (20 - 18.034), 0] ]) {
                    translate(i) union() {
                        color("slategray") translate([-0.775, -0.625, 0]) cube([1.55, 1.25, 0.5]);
                        color("lightgray") for (i = [-0.825, 0.825]) {
                            translate([i - 0.175, -0.65, 0]) cube([0.35, 1.3, 0.55]);
                        }
                    }
                }
                for (i = [ [1.524, (20 - 17.272), 0], [10.414, (20 - 17.018), 0] ]) {
                    translate(i) rotate([0,0,90]) union() {
                        color("slategray") translate([-0.775, -0.625, 0]) cube([1.55, 1.25, 0.5]);
                        color("lightgray") for (i = [-0.825, 0.825]) {
                            translate([i - 0.175, -0.65, 0]) cube([0.35, 1.3, 0.55]);
                        }
                    }
                }
                //0805 C
                for (i = [ [14.732, (20 - 1.524), 0], [9.144, (20 - 7.62), 0], [7.62, (20 - 16.002), 0], [7.62, (20 - 18.034), 0] ]) {
                    translate(i) union() {
                        color("tan") translate([-0.8, -0.625, 0]) cube([1.6, 1.25, 1]);
                        color("lightgray") for (i = [-0.775, 0.775]) {
                            translate([i  -0.125, -0.65, 0]) cube([0.25, 1.3, 1.05]);
                        }
                    }
                }
                for (i = [ [3.81, (20 - 17.272), 0], [9.144, (20 - 12.446), 0], [31.242, (20 - 6.096), 0] ]) {
                    translate(i) rotate([0, 0, 90]) union() {
                        color("tan") translate([-0.8, -0.625, 0]) cube([1.6, 1.25, 1]);
                        color("lightgray") for (i = [-0.775, 0.775]) {
                            translate([i  -0.125, -0.65, 0]) cube([0.25, 1.3, 1.05]);
                        }
                    }
                }
                //3216 TANT
                translate([3.048, (20 - 1.27),0]) union() {
                    color("tan") translate([-1.6, -0.8, 0]) cube([3.2, 1.6, 1.5]);
                    color("lightgray") for (i = [-1.55, 1.55]) {
                        translate([i  -0.125, -0.85, 0]) cube([0.25, 1.7, 1.55]);
                    }
                }
            }
        }
        union() {
            //conn 2x03
            union() {
                for (i = [0:2.54:5.08] ) {
                    for (j = [0:2.54:2.54] ) {
                        translate([41.148 + j,(20 - 7.366) - i, -1]) cylinder(r=0.5, h=3);
                    }
                }
            }
            translate([51,10,-1]) cylinder(r=1.6, h=3);
            translate([55,0,-1]) cylinder(r=3, h=3);
            translate([55,20,-1]) cylinder(r=3, h=3);
        }
    }
}