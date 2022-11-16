#pragma once
#include "LayersInfo.h"
#include "Transform.h"
#include "RenderDataFactory.h"
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <map>

namespace R2grap{

struct PathData {
  bool closed;
  bool has_keyframe;
  std::vector<float> verts;//path's vertices, can have mulitity paths;
  std::vector<unsigned int> tri_ind;//for gerenate EBO array

  //key is frame index
  std::map<unsigned int, std::vector<float>> trans_verts; 
  std::map<unsigned int, std::vector<unsigned int>> trans_tri_ind;
};

struct FillData {
  glm::vec4 color;
  unsigned int opacity;

  //key is frame index
  std::map<unsigned int, glm::vec4> trans_color;
  std::map<unsigned int, unsigned int> trans_opacity;
};

struct StrokeData {
  glm::vec4 color;
  unsigned int opacity;
  float stroke_wid;
  float miter_limit;

  //key is frame index
  std::map<unsigned int, glm::vec4> trans_color;
  std::map<unsigned int, unsigned int> trans_opacity;
  std::map<unsigned int, float> trans_stroke_wid;
  std::map<unsigned int, float> trans_miter_limit;
};

struct GroupData {
  std::vector<PathData> paths;
  FillData fill;
  StrokeData stroke;

  std::vector<glm::mat4> trans;
};

struct LayerData{
  unsigned int index;
  float start_pos;
  float end_pos;
  unsigned int link_layer_index;
  std::vector<GroupData> group_data;
  
  std::vector<glm::mat4> trans;

  //old
  unsigned int paths_num;
  std::vector<std::vector<float>> verts;
  std::vector<std::vector<unsigned int>> triangle_ind;
  std::vector<glm::vec4> color;
};

class RenderContent{
public:
  RenderContent(LayersInfo* layer_info);

  static unsigned int GetRenderPathCount(const std::vector<std::shared_ptr<RenderContent>>& contents);

  static unsigned int GetPathIndex(const std::vector<std::shared_ptr<RenderContent>>& contents, unsigned int layer_ind, unsigned int path_ind);

  LayerData& GetLayerData(){return layer_data_;}
  
  
private:
  LayerData layer_data_;
};

}