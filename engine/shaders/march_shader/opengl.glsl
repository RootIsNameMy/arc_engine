#type vertex
#version 330 core

in vec3 a_position;
in vec2 a_tex_coord;

out vec2 uv;



void main()
{
    gl_Position = vec4(a_position,1);
    uv = a_tex_coord;
}

#type fragment
#version 330 core

out vec4 color;

in vec2 uv;
struct object{
  vec3 pos;
};
uniform object u_object_a;
uniform object u_object_b;
struct dist{
  float d;
  int i;
};

float box(vec3 p, vec3 b){
  return length(max(abs(p)-b,0.0));
}
float sphere(vec3 p,float r){
  return length(p) - r;
}
dist map(vec3 pos){
  dist ret;
  float s = sphere(pos - vec3(0,0,0),2.5f);
  float b = box(pos - vec3 (0.5,2.5 ,0),vec3(2));
  if(b > s){
    ret.d = s;
    ret.i=0;
  }
  else{
    ret.d = b;
    ret.i=1;
  }
  return ret;
}
dist march(vec3 ro, vec3 rd){
  vec3 pos;
  dist t;
  t.d = 0;
  for(int i=0; i<100; ++i){
    pos = ro+t.d*rd;
    dist d = map(pos);
    if(d.d < 0.01){
      t.i = d.i;
      break;
    }
    t.d+=d.d;
    if(t.d > 20){
      t.d=-1;
      break;
    }
  }
  return t;
}
vec3 normal(vec3 p){
  vec2 e = vec2(0.001,0);
  return normalize(vec3(
        map(p+e.xyy).d - map(p-e.xyy).d,
        map(p+e.yxy).d - map(p-e.yxy).d,
        map(p+e.yyx).d - map(p-e.yyx).d));
}
void main()
{
  vec3 ro = vec3(10,-3,10);// get from uniform
  vec3 ta = vec3(0,0,0);
  vec3 ww = normalize(ta - ro);
  vec3 uu = normalize(cross(ww,vec3(0,1,0)));
  vec3 vv = normalize(cross(uu,ww));
  vec3 rd = normalize(uv.x*uu + uv.y*vv + ww*2);

  color=vec4(uv.xy,1,1);

  dist m = march(ro,rd);
  if(m.d>0){
    /* vec3 n = normal(ro+m.d*rd); */
    if(m.i == 1){
      vec3 n = normal(ro+m.d*rd)+1;
      n = n / 2.0;
      color = vec4(n.xyz,1);
    }
    else{
      color = vec4(1,1,0,1);
    }
  }
}
