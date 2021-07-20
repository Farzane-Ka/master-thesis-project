[labeltrain,datatrain]=libsvmread('train.scale');
[labeltest,datatest]=libsvmread('test.scale');

%[C,gamma]=meshgrid(-3:2:10,-8:2:3);
%CV_acc=zeros(numel(C),1);
%for i=1:numel(C)
    %CV_acc(i)= svmtrain(trainlabel,traindata,'-s 0 -g', num2str(2^gamma(i)),'-c', num2str(2^C(i)), '-v 10');
 %  CV_acc(i)= svmtrain(labeltrain,datatrain,...
  %     sprintf('-c %f -g %f -v %d', 2^C(i), 2^gamma(i), 5));
%end
%[a,idx]=max(CV_acc);
%bestgamma=2^gamma(idx);
%bestc=2^C(idx);
%maximumAcc=a;
bestgamma=0.015625000000000;
bestc=2;
model=cell(2,1);

    model{1}=svmtrain(double(labeltrain==-1),datatrain,sprintf('-c %d -g %d -b %d', bestc, bestgamma, 1));%'-c 1 -g 0.2 -b 1');%
    model{2}=svmtrain(double(labeltrain==1),datatrain,sprintf('-c %d -g %d -b %d', bestc, bestgamma, 1));%'-c 1 -g 0.2 -b 1');%

%#swprobability
numtest=30296;
prob=zeros(numtest,2);

    [a,b,p]=svmpredict(double(labeltest==-1),datatest, model{1}, '-b 1');%3khorouji dar predict vojood darad bordary az label va deghat va sevomi matrix az ehtemal ast
    prob(:,1)=p(:,model{1}.Label==1);%khoroujie train yek sakhtar ast ke .label be manie label of each  class ast
    [a,b,p]=svmpredict(double(labeltest==1),datatest, model{2}, '-b 1');%3khorouji dar predict vojood darad bordary az label va deghat va sevomi matrix az ehtemal ast
    prob(:,2)=p(:,model{2}.Label==1);%khoroujie train yek sakhtar ast ke .label be manie label of each  class ast

%# predict the class with the highest probability
[~,pred]=max(prob,[],2);%maximum element in 2th dimention
%accuracy
acc=sum(pred==labeltest) ./numel(labeltest);
C=confusionmat(labeltest,pred);
            





            