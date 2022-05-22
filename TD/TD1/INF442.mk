##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=INF442
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/Users/chhoutlaychiva/INF442
ProjectPath            :=/Users/chhoutlaychiva/INF442
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=L.Chiva CHHOUT
Date                   :=08/03/2022
CodeLitePath           :="/Users/chhoutlaychiva/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="INF442.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/chhoutlaychiva/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(ObjectSuffix) $(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(ObjectSuffix) $(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(ObjectSuffix) $(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(ObjectSuffix): INF442-td1-1-handin/grading/grading.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(DependSuffix) -MM INF442-td1-1-handin/grading/grading.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/chhoutlaychiva/INF442/INF442-td1-1-handin/grading/grading.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(PreprocessSuffix): INF442-td1-1-handin/grading/grading.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/INF442-td1-1-handin_grading_grading.cpp$(PreprocessSuffix) INF442-td1-1-handin/grading/grading.cpp

$(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(ObjectSuffix): INF442-td1-1-handin/gradinglib/gradinglib.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(DependSuffix) -MM INF442-td1-1-handin/gradinglib/gradinglib.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/chhoutlaychiva/INF442/INF442-td1-1-handin/gradinglib/gradinglib.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(PreprocessSuffix): INF442-td1-1-handin/gradinglib/gradinglib.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/INF442-td1-1-handin_gradinglib_gradinglib.cpp$(PreprocessSuffix) INF442-td1-1-handin/gradinglib/gradinglib.cpp

$(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(ObjectSuffix): INF442-td1-1-handin/stats_functions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(DependSuffix) -MM INF442-td1-1-handin/stats_functions.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/chhoutlaychiva/INF442/INF442-td1-1-handin/stats_functions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(PreprocessSuffix): INF442-td1-1-handin/stats_functions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/INF442-td1-1-handin_stats_functions.cpp$(PreprocessSuffix) INF442-td1-1-handin/stats_functions.cpp

$(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(ObjectSuffix): INF442-td1-1-handin/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(DependSuffix) -MM INF442-td1-1-handin/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/chhoutlaychiva/INF442/INF442-td1-1-handin/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(PreprocessSuffix): INF442-td1-1-handin/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/INF442-td1-1-handin_main.cpp$(PreprocessSuffix) INF442-td1-1-handin/main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


